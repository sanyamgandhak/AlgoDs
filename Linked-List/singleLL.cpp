#include <iostream>
using namespace std;


class Node
{
public:
    int key;
    int data;
    Node *next;

    Node()
    {
        data = 0;
        key = 0;
        next = NULL;
    }
    Node(int d, int k)
    {
        key = k;
        data = d;
    }
};

class SinglyLinkedList
{
public:
    Node *start;

    SinglyLinkedList()
    {
        start = NULL;
    }
    SinglyLinkedList(Node *n)
    {
        start = n;
    }
    // 1. check if node exist using key
    Node *nodeExists(int k)
    {
        Node *temp = NULL;
        Node *ptr = start;
        while (ptr != NULL)
        {
            if (ptr->key == k)
            {
                temp = ptr;
            }
            ptr = ptr->next;
        }
        return temp;
    }

    // 2 append a node to the list

    void appendNode(Node *n)
    {
        if (nodeExists(n->key) != NULL)
        {
            cout << "\n @@@@Node exist@@@" << endl;
        }
        else
        {
            if (start == NULL)
            {
                start = n;
                cout << "\nnode appented LINKED LIST is created" << endl;
            }
            else
            {
                Node *ptr = start;

                while (ptr->next != start)
                    ptr = ptr->next;

                ptr->next = n;
                cout << "\nNode appented" << endl;
            }
        }
    }

    // 3.prepand Node -Attach a Node at the start;
    void prependNode(Node *n)
    {
        if (nodeExists(n->key) != NULL)
        {
            cout << "\n @@@@Node exist@@@" << endl;
        }
        else
        {
            n->next = start;
            start = n;
        }
    }

    // 4. Insert a Node aftrer particular node
    void atPosition(int k, Node *n)
    {
        Node *ptr = nodeExists(k);
        if (ptr == NULL)
        {

            cout << "\n @@@@Node not exist@@@" << endl;
        }
        else
        {
            if (nodeExists(n->key) != NULL)
            {
                cout << "\n @@@@Node exist@@@" << endl;
            }
            else
            {
                n->next = ptr->next;
                ptr->next = n;
            }
        }
    }

    void deleteNode(int k)
    {
        if (start == NULL)
        {
            cout << "\n Empty list" << endl;
        }
        else
        {
            if (start->key == k)
            { 
                Node* temp = start;
                start = start->next;
                free(temp);
                cout << "\n Node Unlinked with key value :" << k << endl;
            }
            else
            {
                Node *prevPtr = start;
                Node *temp = NULL;
                Node *currentPtr = start->next;

                while (prevPtr->key != k)
                {
                    temp = prevPtr;
                    prevPtr = prevPtr->next;
                }
                if (temp != NULL)
                {
                    temp->next = prevPtr->next;
                    temp = prevPtr;
                    free(temp);
                }
            }
        }
    }

    // 6.print list

    void printList()
    {
        if (start == NULL)
        {
            cout << "\nNode doesnot exist" << endl;
        }
        else
        {
            cout << endl
                 << "singly Linked List Values :";
            Node *ptr = start;
            while (ptr != NULL)
            {
                cout << "(" << ptr->key << "," << ptr->data << ") -->";
                ptr = ptr->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    SinglyLinkedList s;
    int key1, k1, data1;
    while (1)
    {

        cout << "1.append()" << endl;
        cout << "2.prepend()" << endl;
        cout << "3.insert()" << endl;
        cout << "4.delete()" << endl;
        cout << "5.print()" << endl;

        Node *n1 = new Node();
        char option;
        cout << "\nEnter your choice" << endl;
        cin >> option;
        switch (option)
        {
        case '1':
            cout << "enter yor data :" << endl;
            cin >> data1;
            cin >> key1;
            n1->key = key1;
            n1->data = data1;
            s.appendNode(n1);
            break;

        case '2':
            cout << "enter yor data :" << endl;
            cin >> data1;
            cin >> key1;
            n1->key = key1;
            n1->data = data1;
            s.prependNode(n1);
            break;

        case '3':
            cout << "enter key which is in list : ";
            cin >> k1;
            cout << "enter data : ";
            cin >> data1;
            cout << "Enter key : ";
            cin >> key1;
            n1->key = key1;
            n1->data = data1;
            s.atPosition(k1, n1);
            break;

        case '4':
            cout << "enter a key to delete :";
            cin >> k1;
            s.deleteNode(k1);
            break;
        case '5':
            s.printList();
            break;
        case '6':
            return 0;
            break;
        }
    }
}
