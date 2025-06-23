#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/internet-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/applications-module.h"
#include "ns3/packet-sink.h"

using namespace ns3;

int main(int argc, char *argv[]) {
    // Log components for debugging
    LogComponentEnable("PacketSink", LOG_LEVEL_INFO);
    LogComponentEnable("OnOffApplication", LOG_LEVEL_INFO);

    // Create nodes: n0, n1, n2, n3
    NodeContainer nodes;
    nodes.Create(4);

    // Install the Internet stack
    InternetStackHelper internet;
    internet.Install(nodes);

    // Set up PointToPoint links
    PointToPointHelper link1, link2;
    link1.SetDeviceAttribute("DataRate", StringValue("2Mbps"));
    link1.SetChannelAttribute("Delay", StringValue("10ms"));

    link2.SetDeviceAttribute("DataRate", StringValue("1.7Mbps"));
    link2.SetChannelAttribute("Delay", StringValue("20ms"));

    // Install links between nodes with specific attributes
    NetDeviceContainer devices_n0_n2 = link1.Install(nodes.Get(0), nodes.Get(2));
    NetDeviceContainer devices_n1_n2 = link1.Install(nodes.Get(1), nodes.Get(2));
    NetDeviceContainer devices_n2_n3 = link2.Install(nodes.Get(2), nodes.Get(3));

    // Assign IP addresses
    Ipv4AddressHelper address;
    address.SetBase("10.1.1.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces_n0_n2 = address.Assign(devices_n0_n2);

    address.SetBase("10.1.2.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces_n1_n2 = address.Assign(devices_n1_n2);

    address.SetBase("10.1.3.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces_n2_n3 = address.Assign(devices_n2_n3);

    // Configure TCP traffic (from n1 to n3)
    uint16_t tcpPort = 8080; // Arbitrary port for TCP connection
    Address tcpSinkAddress(InetSocketAddress(interfaces_n2_n3.GetAddress(1), tcpPort));
    PacketSinkHelper tcpSinkHelper("ns3::TcpSocketFactory", tcpSinkAddress);
    ApplicationContainer tcpSinkApp = tcpSinkHelper.Install(nodes.Get(3));
    tcpSinkApp.Start(Seconds(0.5));
    tcpSinkApp.Stop(Seconds(4.0));

    OnOffHelper tcpClient("ns3::TcpSocketFactory", tcpSinkAddress);
    tcpClient.SetAttribute("DataRate", StringValue("1Mbps"));
    tcpClient.SetAttribute("PacketSize", UintegerValue(1024));
    tcpClient.SetAttribute("OnTime", StringValue("ns3::ConstantRandomVariable[Constant=1]"));
    tcpClient.SetAttribute("OffTime", StringValue("ns3::ConstantRandomVariable[Constant=0]"));
    ApplicationContainer tcpClientApp = tcpClient.Install(nodes.Get(1));
    tcpClientApp.Start(Seconds(0.5));
    tcpClientApp.Stop(Seconds(4.0));

    // Configure UDP traffic (from n0 to n3)
    uint16_t udpPort = 8081; // Arbitrary port for UDP connection
    Address udpSinkAddress(InetSocketAddress(interfaces_n2_n3.GetAddress(1), udpPort));
    OnOffHelper udpClient("ns3::UdpSocketFactory", udpSinkAddress);
    udpClient.SetAttribute("DataRate", StringValue("100Kbps"));
    udpClient.SetAttribute("PacketSize", UintegerValue(1024));  // 1 KB
    udpClient.SetAttribute("OnTime", StringValue("ns3::ConstantRandomVariable[Constant=1]"));
    udpClient.SetAttribute("OffTime", StringValue("ns3::ConstantRandomVariable[Constant=0]"));
    ApplicationContainer udpClientApp = udpClient.Install(nodes.Get(0));
    udpClientApp.Start(Seconds(0.1));
    udpClientApp.Stop(Seconds(4.5));

    PacketSinkHelper udpSinkHelper("ns3::UdpSocketFactory", udpSinkAddress);
    ApplicationContainer udpSinkApp = udpSinkHelper.Install(nodes.Get(3));

    // Enable Pcap tracing for visualization
    link1.EnablePcapAll("simple_network");
    link2.EnablePcapAll("simple_network");

    // Run the simulation
    Simulator::Run();
    Simulator::Destroy();

    return 0;
}
