#include "main.hpp"

int main()
{
    DoublyLinkedList dll;

    dll.insertHead(10);
    dll.insertHead(20);
    dll.insertTail(30);
    dll.insertTail(40);
    dll.print();
    return (0);
}