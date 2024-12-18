#ifndef MAIN_H
#define MAIN_H
#include <iostream>
using namespace std;

/**
 * Doubly linked list Node.
 * Stores an integer value at data, pointers for previous and following nodes,
 * and a constructor method for easier usage.
 */
struct Node
{
    int data;
    Node *prev;
    Node *next;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};


/**
 * Doubly linked list class.
 * This class handles the nodes of a linked list, managing methods to insert
 * and display the linked list.
 */
class DoublyLinkedList
{
    private:
        Node *head;
    public:
        DoublyLinkedList(): head(nullptr) {}

        void insertHead(int data)
        {
            Node *node = new Node(data);

            if (head) 
            {
                node->next = head;
                head->prev = node;
            }
            head = node;
        }

        void insertTail(int data)
        {
            Node *node = new Node(data);
            if (!head)
            {
                head = node;
                return;
            }
            Node *temp = head;
            while (temp->next)
                temp = temp->next;
            temp->next = node;
            node->prev = temp;
        }

        void print() {
           Node* temp = head;
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }

        ~DoublyLinkedList()
        {
            Node *temp = head;

            while(temp)
            {
                Node *next = temp->next;
                delete temp;
                temp = next;
            }
        }
};

#endif