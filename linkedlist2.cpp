#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

Node* insertBeginning(Node* head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    return head;
}

Node* insertAfter(Node* head, int value, int key) {
    Node* temp = head;

    // traverse to find key
    while (temp != nullptr && temp->data != key) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Key not found!" << endl;
        return head;
    }

    // creating a new node
    Node* newNode = new Node();
    newNode->data = value;

    // inserting new node
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

Node* insertBefore(Node* head, int key, int value) {
    // Case 1: Empty list
    if (head == nullptr) {
        cout << "List is empty!\n";
        return head;
    }

    // Case 2: Insert before head
    if (head->data == key) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
        return head;
    }

    // Case 3: Insert before middle node
    Node* prev = nullptr;
    Node* curr = head;
    while (curr != nullptr && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == nullptr) {
        cout << "Key not found!\n";
        return head;
    }

    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = curr;
    prev->next = newNode;

    return head;
}

Node* deleteNode(Node* head, int key) {
    // Case 1: Empty list
    if (head == nullptr) {
        cout << "List is empty!\n";
        return head;
    }

    // Case 2: Deleting the head node
    if (head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Node with value " << key << " deleted.\n";
        return head;
    }

    // Case 3: Deleting other nodes
    Node* prev = nullptr;
    Node* curr = head;
    while (curr != nullptr && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == nullptr) {
        cout << "Key not found!\n";
        return head;
    }

    prev->next = curr->next;
    delete curr;
    cout << "Node with value " << key << " deleted.\n";

    return head;
}

void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* first = nullptr; // head
    Node* tail = nullptr;  // tail for easy end insertion

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int value;
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;

        Node* newNode = createNode(value);

        if (first == nullptr) {
            first = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    cout << "Initial Linked List: ";
    display(first);

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
                first = insertBeginning(first, val);
                cout << "Node inserted at beginning.\n";
                break;
            }
            case 2:
                cout << "Linked List: ";
                display(first);
                break;

            case 3: {
                int key, val;
                cout << "Enter the key (node value) after which you want to insert: ";
                cin >> key;
                cout << "Enter value to insert: ";
                cin >> val;
                first = insertAfter(first, val, key);
                break;
            }
            case 4: {
                int key, val;
                cout << "Enter the key (node value) before which you want to insert: ";
                cin >> key;
                cout << "Enter value to insert: ";
                cin >> val;
                first = insertBefore(first, key, val);
                break;
            }
            case 5: {
                int key;
                cout << "Enter the value of the node to delete: ";
                cin >> key;
                first = deleteNode(first, key);
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
