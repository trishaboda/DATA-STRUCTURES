#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        this->data = x;
        this->next = NULL;
    }
};

class List
{
    Node *head, *temp;

public:
    List()
    {
        head = NULL;
        temp = NULL;
    }
    void create();
    void display();
    void insertAtStart(int value);
    void insertAtEnd(int value);
    void insertAtIntermediate(int position, int value);
    void deleteatstart();
    void deleteatend();
    void deleteatposition(int position);
    void deleteanelement(int value);
    void reverse();
    void concat(List &List2);
};

void List::create()
{
    int num;
    cout << "Enter the number of nodes you want to create: ";
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        int value;
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;

        Node *newNode = new Node(value);
        if (head == NULL)
        {
            head = newNode;
            temp = newNode;
            newNode->next = head;
        }
        else
        {
            temp->next = newNode;
            newNode->next = head;
            temp = temp->next;
        }
    }
}
void List::display()
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    temp = head;
    while (temp->next != head)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << temp->data << " -> ";
    temp = temp->next;
    cout << temp->data;
}

void List::insertAtStart(int value)
{

    Node *newnode = new Node(value);
    temp = head;
    while (temp->next != head)
    {
        temp = temp->next; // Temp at last
    }
    newnode->next = head;
    head = newnode;
    temp->next = head;
}

void List::insertAtEnd(int value)
{
    Node *newNode = new Node(value);
    newNode->next = head;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

void List::insertAtIntermediate(int position, int value)
{
    Node *newNode = new Node(value);
    if (position <= 0)
    {
        insertAtStart(value);
        return;
    }
    temp = head;
    for (int i = 0; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    // If temp outside the len of list.
    if (temp == NULL)
    {
        cout << "Position out of bounds." << endl;
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void List::deleteatstart()
{
    Node *q;
    q = temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    head = q->next;
    temp->next = head;
    delete (q);
}

void List::deleteatend()
{
    Node *q;
    temp = head;
    while ((temp->next)->next != head)
    {
        temp = temp->next;
    }
    q = temp->next;
    temp->next = head;
    delete (q);
}

void List::deleteatposition(int position)
{
    if (position == 0)
    {
        deleteatstart();
    }
    else
    {
        Node *q;
        temp = head;
        for (int i = 0; i < position - 1; i++)
        {
            temp = temp->next;
        }
        q = temp->next;
        temp->next = q->next;
        delete (q);
    }
}
void List::deleteanelement(int value)
{
    Node *q;
    temp = head;
    if (temp->data == value) // value found in first node
    {
        head = temp->next;
        delete temp;
    }
    else
    {
        while (temp != NULL) // search for the node
        {
            if (temp->next->data == value)
            {
                // Delete node next to temp
                q = temp->next;
                temp->next = q->next;
                delete q;
                return;
            }
            temp = temp->next;
        }
        cout << "Number not found in the list";
    }
}

void List::reverse()
{
    Node *current, *forward, *Next_node;
    current = head;
    forward = NULL;

    while (current->next != head)
    {
        Next_node = forward;
        forward = current;
        current = current->next;
        forward->next = Next_node;
    }
    Next_node = forward;
    forward = current;
    current = current->next;
    forward->next = Next_node;
    head = forward;
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
}

void List::concat(List &otherList)
{
    if (head == NULL)
    {
        head = otherList.head;
    }
    else
    {
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = otherList.head;

        temp = otherList.head;
        while (temp->next != otherList.head)
        {
            temp = temp->next;
        }
        temp->next = head;
    }
    // Reset the other list to an empty state
    otherList.head = NULL;
    otherList.temp = NULL;
}

int main()
{
    List list;
    List list1;
    List list2;
    int choice;
    do
    {
        cout << "\n******************************************* CIRCULAR LINKED LIST *******************************************" << endl;
        cout << "1. Create List\n";
        cout << "2. Display List\n";
        cout << "3. Insert at Start\n";
        cout << "4. Insert at End\n";
        cout << "5. Insert at Intermediate\n";
        cout << "6. Delete at Intermediate\n";
        cout << "7. Delete at start\n";
        cout << "8. Delete at end\n";
        cout << "9. Delete any particular node\n";
        cout << "10. Reverse\n";
        cout << "11. Concatenation\n";
        cout << "12. Exit\n";
        cout << "************************************************************************************************************" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            list.create();
            break;
        case 2:
            cout << "List elements: ";
            list.display();
            break;
        case 3:
        {
            int startValue;
            cout << "Enter value to insert at the start: ";
            cin >> startValue;
            list.insertAtStart(startValue);
            break;
        }
        case 4:
        {
            int endValue;
            cout << "Enter value to insert at the end: ";
            cin >> endValue;
            list.insertAtEnd(endValue);
            break;
        }
        case 5:
        {
            int position, intermediateValue;
            cout << "Enter position to insert at: ";
            cin >> position;
            cout << "Enter value to insert at position " << position << ": ";
            cin >> intermediateValue;
            list.insertAtIntermediate(position, intermediateValue);
            break;
        }
        case 6:
        {
            int position;
            cout << "Enter position to delete at: ";
            cin >> position;
            list.deleteatposition(position);
            break;
        }
        case 7:
        {
            list.deleteatstart();
            break;
        }
        case 8:
        {
            list.deleteatend();
            break;
        }
        case 9:
        {
            int value;
            cout << "Enter value to delete: ";
            cin >> value;
            list.deleteanelement(value);
            break;
        }
        case 10:
        {
            list.reverse();
            list.display();
            break;
        }
        case 11:
        {
            cout << "Creating List 1:\n";
            list1.create();

            cout << "Creating List 2:\n";
            list2.create();

            cout << "Concatenating List 2 to List 1:\n";
            list1.concat(list2);
            cout << "Lists concatenated." << endl;
            list1.display();
            break;
        }
        case 12:
        {
            cout << "Exiting\n";
            break;
        }
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 12);
    return 0;
}