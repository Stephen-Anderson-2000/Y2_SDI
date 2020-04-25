#include <iostream>

using namespace std;

struct Node
{
    string data;
    Node* next;
};

class LinkedList
{
private:
    Node* head;
    Node* tail;
public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void Add(string newData)
    {
        Node* tempNode = new Node;
        tempNode->data = newData;
        tempNode->next = NULL;

        if (head == NULL)
        {
            head = tempNode;
            tail = tempNode;
        }
        else
        {
            tail->next = tempNode;
            tail = tail->next;
        }
    }
};