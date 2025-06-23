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

