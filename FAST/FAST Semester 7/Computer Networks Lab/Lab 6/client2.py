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

