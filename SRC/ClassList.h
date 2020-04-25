#include <iostream>

using namespace std;

struct Node
{
    string data;
    Node* next;
};

class LinkedListString
{
private:
    Node* head;
    Node* tail;
    int count;
public:
    LinkedListString()
    {
        head = NULL;
        tail = NULL;
        count = 0;
    }

    int Count()
    {
        return count;
    }

    void Add(string newData)
    {
        Node* tempNode = new Node;
        tempNode->data = newData;
        tempNode->next = NULL;
        count += 1;

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

    string At(int position)
    {
        if (head == NULL || position < 0 || position >= count) {
            return "";
        }

        else
        {
            Node* tempNode = new Node(*head);
            for (int i = 0; i < position; i++)
            {
                tempNode = tempNode->next;
            }
            return tempNode->data;
        }


    }

    void Remove(int position)
    {
        if (head == NULL || position < 0 || position >= count)
        {
            return;
        }

        Node* deletedNode;

        if (position == 0) {
            deletedNode = head;
            head = head->next;
            delete deletedNode;
            return;
        }

        else {

            Node* tempNode = new Node(*head);

            for (int i = 0; i < position - 1; i++)
            {
                tempNode = tempNode->next;
            }

            if (position < count - 2)
            {
                deletedNode = tempNode->next;
                tempNode->next = tempNode->next->next;
                delete deletedNode;
            }

            else
            {

                deletedNode = tempNode->next;
                tempNode->next = NULL;
                tail = NULL;
                delete deletedNode;
            }

            return;
        }
    }


};