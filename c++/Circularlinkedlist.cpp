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

// Insert at beginning
Node* insertBeginning(Node* head, int value) {
    Node* newNode = createNode(value);

    if (!head) {                 // empty list
        newNode->next = newNode;
        return newNode;
    }

    Node* tail = head;
    while (tail->next != head)
        tail = tail->next;

    newNode->next = head;
    tail->next = newNode;
    head = newNode;
    return head;
}

// Insert after a key
Node* insertAfter(Node* head, int key, int value) {
    if (!head) {
        cout << "List is empty!\n";
        return head;
    }

    Node* curr = head;
    do {
        if (curr->data == key) {
            Node* newNode = createNode(value);
            newNode->next = curr->next;
            curr->next = newNode;
            return head;
        }
        curr = curr->next;
    } while (curr != head);

    cout << "Key not found!\n";
    return head;
}

// Insert before a key
Node* insertBefore(Node* head, int key, int value) {
    if (!head) {
        cout << "List is empty!\n";
        return head;
    }

    Node* prev = nullptr;
    Node* curr = head;

    // special case: insert before head
    if (head->data == key) {
        Node* newNode = createNode(value);
        Node* tail = head;
        while (tail->next != head)
            tail = tail->next;
        newNode->next = head;
        tail->next = newNode;
        head = newNode;
        return head;
    }

    do {
        prev = curr;
        curr = curr->next;
        if (curr->data == key) {
            Node* newNode = createNode(value);
            prev->next = newNode;
            newNode->next = curr;
            return head;
        }
    } while (curr != head);

    cout << "Key not found!\n";
    return head;
}

// Delete a node by key
Node* deleteNode(Node* head, int key) {
    if (!head) {
        cout << "List is empty!\n";
        return head;
    }

    Node* curr = head;
    Node* prev = nullptr;

    // Deleting head node
    if (head->data == key) {
        if (head->next == head) { // only one node
            delete head;
            cout << "Node with value " << key << " deleted.\n";
            return nullptr;
        }
        Node* tail = head;
        while (tail->next != head)
            tail = tail->next;
        Node* temp = head;
        head = head->next;
        tail->next = head;
        delete temp;
        cout << "Node with value " << key << " deleted.\n";
        return head;
    }

    // Delete other nodes
    prev = head;
    curr = head->next;
    while (curr != head) {
        if (curr->data == key) {
            prev->next = curr->next;
            delete curr;
            cout << "Node with value " << key << " deleted.\n";
            return head;
        }
        prev = curr;
        curr = curr->next;
    }

    cout << "Key not found!\n";
    return head;
}

// Display the list
void display(Node* head) {
    if (!head) {
        cout << "List is empty!\n";
        return;
    }
    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(back to head)\n";
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    // Create initial circular list
    for (int i = 0; i < n; i++) {
        int value;
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;
        Node* newNode = createNode(value);
        if (!head) {
            head = tail = newNode;
            tail->next = head;       // point to itself
        } else {
            tail->next = newNode;
            newNode->next = head;
            tail = newNode;
        }
    }

    cout << "Initial Circular Linked List: ";
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
                cout << "Circular Linked List: ";
                display(head);
                break;
            case 3: {
                int key, val;
                cout << "Enter key (node value) after which to insert: ";
                cin >> key;
                cout << "Enter value to insert: ";
                cin >> val;
                head = insertAfter(head, key, val);
                break;
            }
            case 4: {
                int key, val;
                cout << "Enter key (node value) before which to insert: ";
                cin >> key;
                cout << "Enter value to insert: ";
                cin >> val;
                head = insertBefore(head, key, val);
                break;
            }
            case 5: {
                int key;
                cout << "Enter value of node to delete: ";
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
