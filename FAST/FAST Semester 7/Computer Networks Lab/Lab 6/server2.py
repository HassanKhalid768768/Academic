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

