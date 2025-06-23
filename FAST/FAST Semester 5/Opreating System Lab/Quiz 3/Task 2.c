#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define N 10

// Define the structure for a node in the linked list
struct Node {
    int studentid;
    char name[20];
    float grade;
    struct Node *next;	
};

// Function to create a new node with the given data
struct Node* createNode(int studentid, char name[20], char grade) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->studentid = studentid;
    strcpy(new_node->name, name);
    new_node->grade = grade;
    new_node->next = NULL;
    return newNode;
}

}

void delete_node(int id) {
    Node *current = current->head;
    Node *prev = NULL;

    while (current != NULL) {
        if (current->id == id) {
            if (prev == NULL) {
                shared_list->head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            shared_list->count--;
            return;
        }
        prev = current;
        current = current->next;
    }
}


// Function to display the elements of the linked list
void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to free the memory occupied by the linked list
void freeList(struct Node* head) {
    struct Node* current = head;
    struct Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

void *process1(void *arg1, void *arg2, void *arg3) {
    search_and_display(arg1, arg2, arg3);
    return NULL;
}

void *process2(void *arg1, void *arg2, void *arg3) {
    search_and_display(arg1, arg2, arg3);
    return NULL;
}

void search_and_display() {
    Node *current = head;

    while (current != NULL) {
        printf("ID: %d, Name: %s, Grade: %s\n", current->studentid, current->name, current->grade);
        current = current->next;
    }
}

int main() {
    struct Node* head = NULL;

    // Insert nodes at the beginning
    head = createNode(3, "Hassan", "C");
    head = createNode(2, "Hamza", "B");
    head = createNode(1, "Ahmad", "A");

    printf("Linked List after insertions at the beginning: ");
    displayList(head);

    // initialize two threads for the variables
    pthread_t thread1, thread2;
    
    // create threads
    pthread_create(&thread1, NULL, process1, head);
    pthread_create(&thread2, NULL, process2, head);
    
    // join threads
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    
    // Free the memory occupied by the linked list
    freeList(head);

    return 0;
}

