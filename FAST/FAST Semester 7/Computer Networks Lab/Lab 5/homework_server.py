import socket
import threading

MAX_CLIENTS = 3
connected_clients = 0
lock = threading.Lock()

def handle_client(client_socket, client_address):
    global connected_clients
    print(f"[NEW CONNECTION] {client_address} connected.")
    while True:
        try:
            message = client_socket.recv(1024).decode('utf-8')
            if not message:
                break

            if message == "DISCONNECT":
                print(f"[DISCONNECT] {client_address} disconnected.")
                client_socket.send("DISCONNECT".encode('utf-8'))
                break
            else:
                print(f"[RECEIVED] {message} from {client_address}")
                client_socket.send(message.encode('utf-8'))

        except Exception as e:
            print(f"[ERROR] {e}")
            break

    with lock:
        connected_clients -= 1
    client_socket.close()

def start_server(server_ip, server_port):
    global connected_clients

    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind((server_ip, server_port))
    server.listen()
    print(f"[LISTENING] Server is listening on {server_ip}:{server_port}")

    while True:
        client_socket, client_address = server.accept()

        with lock:
            if connected_clients >= MAX_CLIENTS:
                print(f"[SERVER FULL] Rejecting connection from {client_address}")
                client_socket.send("Server Full".encode('utf-8'))
                client_socket.close()
            else:
                connected_clients += 1
                client_handler = threading.Thread(target=handle_client, args=(client_socket, client_address))
                client_handler.start()

if __name__ == "__main__":
    SERVER_IP = "127.0.0.1"
    SERVER_PORT = 5555
    start_server(SERVER_IP, SERVER_PORT)

