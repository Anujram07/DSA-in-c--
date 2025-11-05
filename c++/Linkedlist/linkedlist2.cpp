#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Create a new node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

// Insert at the beginning
Node* insertBeginning(Node* head, int value) {
    Node* newNode = createNode(value);
    newNode->next = head;
    return newNode;
}

// Insert after a key
Node* insertAfter(Node* head, int value, int key) {
    Node* temp = head;

    while (temp && temp->data != key)
        temp = temp->next;

    if (!temp) {
        cout << "Key not found!\n";
        return head;
    }

    Node* newNode = createNode(value);
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

// Insert before a key
Node* insertBefore(Node* head, int key, int value) {
    if (!head) {
        cout << "List is empty!\n";
        return head;
    }

    if (head->data == key) {  // Insert before head
        Node* newNode = createNode(value);
        newNode->next = head;
        return newNode;
    }

    Node* prev = nullptr;
    Node* curr = head;
    while (curr && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    if (!curr) {
        cout << "Key not found!\n";
        return head;
    }

    Node* newNode = createNode(value);
    newNode->next = curr;
    prev->next = newNode;

    return head;
}

// Delete a node by key
Node* deleteNode(Node* head, int key) {
    if (!head) {
        cout << "List is empty!\n";
        return head;
    }

    if (head->data == key) {  // Delete head
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Node with value " << key << " deleted.\n";
        return head;
    }

    Node* prev = nullptr;
    Node* curr = head;
    while (curr && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    if (!curr) {
        cout << "Key not found!\n";
        return head;
    }

    prev->next = curr->next;
    delete curr;
    cout << "Node with value " << key << " deleted.\n";

    return head;
}

// Display the list
void display(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    // Create initial list
    for (int i = 0; i < n; i++) {
        int value;
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;

        Node* newNode = createNode(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    cout << "Initial Linked List: ";
    display(head);

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Display List\n";
        cout << "3. Insert after a node\n";
        cout << "4. Insert before a node\n";
        cout << "5. Delete a node\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int val;
                cout << "Enter value to insert at beginning: ";
                cin >> val;
                head = insertBeginning(head, val);
                cout << "Node inserted at beginning.\n";
                break;
            }
            case 2:
                cout << "Linked List: ";
                display(head);
                break;
            case 3: {
                int key, val;
                cout << "Enter the key after which you want to insert: ";
                cin >> key;
                cout << "Enter value to insert: ";
                cin >> val;
                head = insertAfter(head, val, key);
                break;
            }
            case 4: {
                int key, val;
                cout << "Enter the key before which you want to insert: ";
                cin >> key;
                cout << "Enter value to insert: ";
                cin >> val;
                head = insertBefore(head, key, val);
                break;
            }
            case 5: {
                int key;
                cout << "Enter value of the node to delete: ";
                cin >> key;
                head = deleteNode(head, key);
                break;
            }
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}
