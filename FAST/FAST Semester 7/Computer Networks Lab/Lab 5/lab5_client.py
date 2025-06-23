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

