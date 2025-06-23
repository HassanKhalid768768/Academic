import socket

def main():
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_address = ('127.0.0.1', 2000)

    try:
        client_socket.connect(server_address)
        print("Connected to server")
    except socket.error as err:
        print(f"Connection failed. Error: {err}")
        return

    # Client sends its ID
    while True:
    	client_id = input("Enter your ID (0-9): ")
    	if client_id.isdigit() and 0 <= int(client_id) <= 9:
    		break
    	else:
        	print("Invalid ID. Please enter a single digit (0-9).")
        #client_socket.close()
        #return

    client_message = f"Hello I am client and My id is {client_id}"
    
    try:
        client_socket.send(client_message.encode('utf-8'))
    except socket.error as err:
        print(f"Send failed. Error: {err}")
        client_socket.close()
        return

    try:
        server_message = client_socket.recv(1024).decode('utf-8')
        print(f"Server Message: {server_message}")
    except socket.error as err:
        print(f"Receive failed. Error: {err}")

    client_socket.close()

if __name__ == "__main__":
    main()

