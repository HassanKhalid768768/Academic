# udp server
import socket
import re

students = []

# Check-in Function
def check_in(student_rollnumber):
    if student_rollnumber in students:
        return f"You are already here."
    else:
        students.append(student_rollnumber)
        return f"Welcome Student {student_rollnumber}"

# Check-out Function
def check_out(student_rollnumber):
    if student_rollnumber not in students:
        return f"You didn’t check in today. Contact System Administrator."
    else:
        students.remove(student_rollnumber)
        return f"Goodbye Student {student_rollnumber}! Have a nice day."

def process_packet(packet):
    pattern = r'^\d{2}-\d{4}-(CI|CO)$'

    if not re.match(pattern, packet):
        return "Invalid packet format."
    
    # Split the packet
    student_rollnumber, action = packet.rsplit('-', 1)
    
    if action == "CI":
        return check_in(student_rollnumber)
    elif action == "CO":
        return check_out(student_rollnumber)
    else:
        return "Invalid action."

def start_udp_server():
    # Create a UDP socket
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    server_socket.bind(("127.0.0.1", 2000))
    
    print("Socket created and bound")
    print("Listening for messages...\n")
    
    while True:
        # Receive message from client
        packet, client_address = server_socket.recvfrom(2000)
        client_message = packet.decode('utf-8')
        
        # Process the incoming packet
        response = process_packet(client_message)
        
        # Send back the response to the client
        server_socket.sendto(response.encode('utf-8'), client_address)
        
        print("Current students in the system:")
        if students:
            for idx, student in enumerate(students, 1):
                print(f"{idx}: {student}")
        else:
            print("No students checked in.")

if __name__ == "__main__":
    start_udp_server()




# udp client
import socket

def start_udp_client():
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    
    server_address = ("127.0.0.1", 2000)
    
    while True:

        message = input("Enter your roll number-CI/CO. For example 21-5692-CI for check-in or 21-5692-CO for check-out:")
        
        # Sending message to server
        client_socket.sendto(message.encode('utf-8'), server_address)
        
        # Receiving message from server
        response, _ = client_socket.recvfrom(2000)
        print(f"Server Message: {response.decode('utf-8')}")

    client_socket.close()

if __name__ == "__main__":
    start_udp_client()





#tcp server
import socket

def invert_vowel_words(message):
    words = message.split()
    inverted_words = []
    
    for word in words:
        # Check if the word contains any vowels
        if any(char in 'aeiouAEIOU' for char in word):
            inverted_words.append(word[::-1])
        else:
            inverted_words.append(word)
    
    return ' '.join(inverted_words)

def main():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_address = ('127.0.0.1', 2000)

    try:
        server_socket.bind(server_address)
        print("Socket bound to IP and port")
    except socket.error as err:
        print(f"Bind failed. Error: {err}")
        return

    server_socket.listen(5)
    print("Server listening for incoming connections...")

    while True:
        client_socket, client_address = server_socket.accept()
        print(f"Client connected: {client_address}")

        try:
            client_message = client_socket.recv(1024).decode('utf-8')
            print(f"Client Message: {client_message}")

            # Invert words containing vowels
            server_response = invert_vowel_words(client_message)

            # Display the server's inverted message
            print(f"Server Inverted Message: {server_response}")
            
            # Send the inverted message back to the client
            client_socket.send(server_response.encode('utf-8'))
        except socket.error as err:
            print(f"Error: {err}")

        client_socket.close()

if __name__ == "__main__":
    main()



#tcp client
import socket

def invert_non_vowel_words(message):
    words = message.split()
    inverted_words = []
    
    for word in words:
        if all(char not in 'aeiouAEIOU' for char in word):
            inverted_words.append(word[::-1])
        else:
            inverted_words.append(word)
    
    return ' '.join(inverted_words)

def main():
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_address = ('127.0.0.1', 2000)

    try:
        client_socket.connect(server_address)
        print("Connected to server")
    except socket.error as err:
        print(f"Connection failed. Error: {err}")
        return

    client_message = input("Enter a string to send to server: ")

    try:
        client_socket.send(client_message.encode('utf-8'))
    except socket.error as err:
        print(f"Send failed. Error: {err}")
        client_socket.close()
        return

    try:
        server_message = client_socket.recv(1024).decode('utf-8')
        print(f"Server Message: {server_message}")

        # Invert words with no vowels
        result_message = invert_non_vowel_words(server_message)
        print(f"Client Inverted Message: {result_message}")
    except socket.error as err:
        print(f"Receive failed. Error: {err}")

    client_socket.close()

if __name__ == "__main__":
    main()



#tcp multi server
import socket
import threading

# File paths
VOTERS_FILE = 'Voters_List.txt'
CANDIDATES_FILE = 'Candidates_List.txt'
VOTES_RECORD_FILE = 'Vote_Records.txt'

# Load voters from file
def load_voters():
    voters = {}
    with open(VOTERS_FILE, 'r') as f:
        for line in f:
            name, cnic = line.strip().split('/')
            voters[cnic] = name
    return voters

# Load candidates from file
def load_candidates():
    candidates = {}
    with open(CANDIDATES_FILE, 'r') as f:
        for line in f:
            name, symbol = line.strip().split('\t')
            candidates[symbol] = name
    return candidates

# Function to handle each client connection
def handle_client(client_socket, address, voters, candidates, voted_cnic):
    try:
        while True:
            # Prompt for Name and CNIC until the correct format is provided
            while True:
                client_socket.send(b"Enter your Name and CNIC separated by '/': ")
                voter_info = client_socket.recv(1024).decode().strip()

                # Validate format
                if '/' in voter_info:
                    name, cnic = voter_info.split('/', 1)
                    break
                else:
                    client_socket.send(b"Invalid format. Please try again.\n")

            # Check if the client has already voted
            if cnic in voted_cnic:
                client_socket.send(b"You have already voted. Try logging in with a different user.\n")
                continue  # Loop back to ask for a new Name and CNIC

            # Authenticate voter
            if voters.get(cnic) == name:
                welcome_message = "Welcome, {}! Here are the candidates:\n".format(name)
                client_socket.send(welcome_message.encode())
                for symbol, candidate_name in candidates.items():
                    client_socket.send(f"{candidate_name} - {symbol}\n".encode())
                
                # Loop until a valid vote symbol is entered
                while True:
                    client_socket.send(b"Please cast your vote by entering the candidate's symbol: ")
                    vote = client_socket.recv(1024).decode().strip()

                    # Record vote if valid symbol is provided
                    if vote in candidates:
                        with open(VOTES_RECORD_FILE, 'a') as f:
                            f.write(f"{name}/{cnic} voted for {candidates[vote]}\n")
                        voted_cnic.add(cnic)
                        client_socket.send(b"Thank you for voting!\n")
                        break  # Exit vote entry loop after a valid vote
                    else:
                        client_socket.send(b"Invalid vote symbol. Please try again.\n")
                
                continue  # Go back to ask for a new user after voting

            else:
                client_socket.send(b"Authentication failed. Please try again.\n")

    except Exception as e:
        print(f"Error handling client {address}: {e}")
    finally:
        client_socket.close()

# Main server function
def server_program():
    host = '127.0.0.1'  # localhost
    port = 5000         # Port to listen on

    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind((host, port))
    server_socket.listen(5)
    print("Server started. Waiting for connections...")

    # Load voter and candidate data
    voters = load_voters()
    candidates = load_candidates()
    voted_cnic = set()  # Set to store CNICs of those who have already voted

    while True:
        client_socket, address = server_socket.accept()
        print(f"Connection from {address}")
        client_handler = threading.Thread(target=handle_client, args=(client_socket, address, voters, candidates, voted_cnic))
        client_handler.start()

if __name__ == "__main__":
    server_program()




#tcp multi client
import socket

def client_program():
    host = '127.0.0.1'  # Server address
    port = 5000         # Server port

    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect((host, port))

    try:
        # Receive server messages and respond
        while True:
            message = client_socket.recv(1024).decode()
            if not message:
                break
            print(message, end="")

            if "Disconnecting" in message:
                break

            # Send user input as a response
            client_input = input()
            client_socket.send(client_input.encode())

    except Exception as e:
        print(f"An error occurred: {e}")
    finally:
        client_socket.close()

if __name__ == "__main__":
    client_program()



# python
import ns.core
import ns.internet
import ns.network
import ns.point_to_point
import ns.applications

def main():
    # Enable logging for UDP Echo Client and Server
    ns.core.LogComponentEnable("UdpEchoClientApplication", ns.core.LOG_LEVEL_INFO)
    ns.core.LogComponentEnable("UdpEchoServerApplication", ns.core.LOG_LEVEL_INFO)

    # Create two nodes
    nodes = ns.network.NodeContainer()
    nodes.Create(2)

    # Configure the point-to-point link
    pointToPoint = ns.point_to_point.PointToPointHelper()
    pointToPoint.SetDeviceAttribute("DataRate", ns.network.StringValue("10Mbps"))
    pointToPoint.SetChannelAttribute("Delay", ns.network.StringValue("5ms"))

    # Install network devices on nodes
    devices = pointToPoint.Install(nodes)

    # Install the Internet stack on nodes
    stack = ns.internet.InternetStackHelper()
    stack.Install(nodes)

    # Assign IP addresses to the devices
    address = ns.internet.Ipv4AddressHelper()
    address.SetBase(ns.network.Ipv4Address("10.1.1.0"), ns.network.Ipv4Mask("255.255.255.0"))
    interfaces = address.Assign(devices)

    # Configure the UDP echo server on Node B
    echoServer = ns.applications.UdpEchoServerHelper(8080)
    serverApps = echoServer.Install(nodes.Get(1))
    serverApps.Start(ns.core.Seconds(1.0))
    serverApps.Stop(ns.core.Seconds(10.0))

    # Configure the UDP echo client on Node A
    echoClient = ns.applications.UdpEchoClientHelper(interfaces.GetAddress(1), 8080)
    echoClient.SetAttribute("MaxPackets", ns.core.UintegerValue(5))
    echoClient.SetAttribute("Interval", ns.core.TimeValue(ns.core.Seconds(0.5)))
    echoClient.SetAttribute("PacketSize", ns.core.UintegerValue(512))

    clientApps = echoClient.Install(nodes.Get(0))
    clientApps.Start(ns.core.Seconds(2.0))
    clientApps.Stop(ns.core.Seconds(10.0))

    # Run the simulation
    ns.core.Simulator.Run()
    ns.core.Simulator.Destroy()

if __name__ == '__main__':
    main()




#c++
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


Router>enable
Router#configure terminal
Router(config)# interface fastethernet 0/0
Router(config)# ip address 192.168.1.1 255.255.255.0
Router(config)# no shutdown
Router(config)# exit
Router(config)# ip dhcp pool name
Router(dhcp-config)# network 192.168.1.2 255.255.255.0
Router(dhcp-config)# default-router 192.168.1.1
Router(dhcp-config)# exit
Router(config)#ip dhcp excluded-address 192.168.1.4 192.168.1.7
Router(config)# exit


Router&gt;enable
Router#configure terminal
Router(config)#router rip
Router(config-router)#version 2
Router(config-router)#no auto-summary
Router(config-router)#network 172.19.0.0
Router(config-router)#network 172.19.32.0
Router(config-router)#network 172.19.160.0
Router(config-router)#exit
Router(config)#exit

exit
Router(config)# router ospf 1
network 10.0.0.0 0.255.255.255 area 0
exit

Step 3: bgp configuration on Router R1:
R1(config)#router bgp 1
R1(config-router)#neighbor 172.16.0.2 remote-as 71
R1(config-router)#network 10.0.0.0 mask 255.0.0.0
R1(config-router)#exit
R1(config)#do write
Building configuration...[OK]
R1(config)#
Step 4: bgp configuration on Router R2:
R2(config)#router bgp 71
R2(config-router)#neighbor 172.16.0.1 remote-as 1
R2(config-router)#neighbor 172.14.0.2 remote-as 79
R2(config-router)#network 40.0.0.0 mask 255.0.0.0
R2(config-router)#exit
R2(config)#do write
Building configuration...[OK]
R2(config)#
Step 5: bgp configuration on Router R3:
R3(config)#router bgp 79
R3(config-router)#neighbor 172.14.0.1 remote-as 71
R3(config-router)#network 40.0.0.0 mask 255.0.0.0
R3(config-router)#exit
R3(config)#do write
Building configuration...[OK
R3(config)#

