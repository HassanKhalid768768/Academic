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
