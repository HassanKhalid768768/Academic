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

