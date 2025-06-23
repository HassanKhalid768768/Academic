import socket

def start_client(server_ip, server_port):
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client.connect((server_ip, server_port))

    print(f"Connected to server {server_ip}:{server_port}")
    while True:
        message = input("Enter message: ")

        # Send message to server
        client.send(message.encode('utf-8'))

        if message == "DISCONNECT":
            break

        # Wait for the server's response
        response = client.recv(1024).decode('utf-8')
        print(f"Server response: {response}")

        if response == "DISCONNECT":
            break

    client.close()

if __name__ == "__main__":
    SERVER_IP = "127.0.0.1"
    SERVER_PORT = 5555
    start_client(SERVER_IP, SERVER_PORT)

