#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node* head = NULL;
    Node* temp;
    int n, x;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter elements: ";

    for (int i = 0; i < n; i++) {
        cin >> x;

        Node* newNode = new Node{x, NULL};

        if (head == NULL)
            head = newNode;
        else {
            temp = head;

            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newNode;
        }
    }

    Node* prev = NULL;
    Node* current = head;
    Node* next;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;

    cout << "Reversed List: ";

    temp = head;

    while (temp != NULL) {
        cout << temp->data;

        if (temp->next != NULL)
            cout << " -> ";

        temp = temp->next;
    }

    cout << " -> NULL";

    return 0;
}
