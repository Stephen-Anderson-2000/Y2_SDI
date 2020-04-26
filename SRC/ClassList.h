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
            count -= 1;
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
                tempNode->next = deletedNode->next;
                delete deletedNode;
                count -= 1;
            }

            else
            {

                deletedNode = tempNode->next;
                tempNode->next = NULL;
                tail = tempNode;
                delete deletedNode;
                count -= 1;
            }

            return;
        }
    }

    LinkedListString Sort(int order)
    {
        //Order 0 = Regular / Ascending, 1 = Reverse / Descending
        //bubble sort
        
        LinkedListString tempList;
        return tempList;
    }

    LinkedListString Search(string term)
    {
        LinkedListString tempList;
        std::string tempString;
        if (term != "")
        {
            for (int i = 0; i < count; i++) {
                tempString = this->At(i);
                if (tempString.find(term) != std::string::npos)
                {
                    tempList.Add(tempString);
                }
            }
        }
        else
        {
            tempList = *this;
        }
        return tempList;
    }

};
