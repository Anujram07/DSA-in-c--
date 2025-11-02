#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

Node* insertBeginning(Node* head, int value) {
    Node* newNode = createNode(value);
    newNode->next = head;
    if (head) head->prev = newNode;
    head = newNode;
    return head;
}

Node* insertAfter(Node* head, int key, int value) {
    Node* temp = head;
    while (temp && temp->data != key)
        temp = temp->next;

    if (!temp) {
        cout << "Key not found!\n";
        return head;
    }

    Node* newNode = createNode(value);
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next) temp->next->prev = newNode;
    temp->next = newNode;

    return head;
}

Node* insertBefore(Node* head, int key, int value) {
    if (!head) {
        cout << "List is empty!\n";
        return head;
    }

    // Insert before head
    if (head->data == key) {
        Node* newNode = createNode(value);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return head;
    }

    Node* curr = head;
    while (curr && curr->data != key)
        curr = curr->next;

    if (!curr) {
        cout << "Key not found!\n";
        return head;
    }

    Node* newNode = createNode(value);
    newNode->next = curr;
    newNode->prev = curr->prev;
    if (curr->prev) curr->prev->next = newNode;
    curr->prev = newNode;

    return head;
}

Node* deleteNode(Node* head, int key) {
    if (!head) {
        cout << "List is empty!\n";
        return head;
    }

    Node* curr = head;
    while (curr && curr->data != key)
        curr = curr->next;

    if (!curr) {
        cout << "Key not found!\n";
        return head;
    }

    if (curr->prev) curr->prev->next = curr->next;
    else head = curr->next;             // deleting head

    if (curr->next) curr->next->prev = curr->prev;

    delete curr;
    cout << "Node with value " << key << " deleted.\n";
    return head;
}

void display(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " <-> ";
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

    for (int i = 0; i < n; i++) {
        int value;
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;

        Node* newNode = createNode(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    cout << "Initial Doubly Linked List: ";
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
                cout << "Doubly Linked List: ";
                display(head);
                break;
            case 3: {
                int key, val;
                cout << "Enter the key (node value) after which you want to insert: ";
                cin >> key;
                cout << "Enter value to insert: ";
                cin >> val;
                head = insertAfter(head, key, val);
                break;
            }
            case 4: {
                int key, val;
                cout << "Enter the key (node value) before which you want to insert: ";
                cin >> key;
                cout << "Enter value to insert: ";
                cin >> val;
                head = insertBefore(head, key, val);
                break;
            }
            case 5: {
                int key;
                cout << "Enter the value of the node to delete: ";
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
