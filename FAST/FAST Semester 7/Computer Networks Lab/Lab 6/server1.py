import socket

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

            # Extract client ID
            client_id = client_message.split()[-1]
            server_response = f"Hello I am server. Your received id is {client_id}"
            client_socket.send(server_response.encode('utf-8'))
        except socket.error as err:
            print(f"Error: {err}")

        client_socket.close()

if __name__ == "__main__":
    main()

