#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertEnd(Node*& head, int x) {
    Node* newNode = new Node{x, NULL};

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

int main() {
    Node* head = NULL;
    int n, x, key, count = 0;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter elements: ";

    for (int i = 0; i < n; i++) {
        cin >> x;
        insertEnd(head, x);
    }

    cout << "Enter key: ";
    cin >> key;

    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL) {

        if (temp->data == key) {
            count++;

            if (prev == NULL) {
                head = temp->next;
                delete temp;
                temp = head;
            }
            else {
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
            }
        }
        else {
            prev = temp;
            temp = temp->next;
        }
    }

    cout << "Count: " << count << endl;

    cout << "Updated Linked List: ";

    temp = head;

    while (temp != NULL) {
        cout << temp->data;

        if (temp->next != NULL)
            cout << " -> ";

        temp = temp->next;
    }

    return 0;
}

