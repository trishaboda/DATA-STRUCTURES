#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;

    node(int x)
    {
        this->data = x;
        this->next = NULL;
    }
};
class linkedlist
{
public:
    node *head;
    node *temp;
    linkedlist()
    {
        head = NULL;
        temp = NULL;
    }

    void create()
    {
        int num;
        cout << "Enter the number of nodes you want to create: ";
        cin >> num;

        for (int i = 0; i < num; i++)
        {
            int x;
            cout << "Enter value for node " << i + 1 << ": ";
            cin >> x;
            node *new_node = new node(x);
            if (head == NULL)
            {
                head = temp = new_node;
            }
            else
            {
                temp->next = new_node;
                temp = new_node;
            }
        }
    }

    void insertathead(int x)
    {
        node *new_node = new node(x);
        new_node->next = head;
        head = new_node;
    }

    void insertattail(int x)
    {
        if (head == NULL)
        {
            insertathead(x);
            return;
        }
        node *new_node = new node(x);
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        // at tail
        temp->next = new_node;
    }

    void insertatpos(int x, int pos)
    {
        if (pos == 0)
        {
            insertathead(x);
            return;
        }
        node *new_node = new node(x);
        temp = head;
        int current_pos = 0;
        while (current_pos != pos - 1)
        {
            temp = temp->next;
            current_pos++;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }

    void insertatdata(int x, int olddata)
    {
        if (head == NULL)
        {
            insertathead(x);
            return;
        }
        node *new_node = new node(x);
        temp = head;
        while (temp->data != olddata)
        {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
    void print()
    {
        if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }
        temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void updateathead(int x)
    {
        if (head == NULL)
        {
            insertathead(x);
            return;
        }
        head->data = x;
    }

    void updateattail(int x)
    {
        if (head == NULL)
        {
            insertathead(x);
            return;
        }
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->data = x;
    }

    void updateatpos(int x, int pos)
    {
        temp = head;
        int current_pos = 0;
        while (current_pos != pos)
        {
            temp = temp->next;
            current_pos++;
        }
        temp->data = x;
    }

    void updateatdata(int x, int olddata)
    {
        temp = head;
        while (temp->data != olddata)
        {
            temp = temp->next;
        }
        temp->data = x;
    }

    void deleteathead()
    {
        temp = head; // node to be deleted
        head = temp->next;
        delete (temp);
    }

    void deleteattail()
    {
        temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        node *temp2 = temp->next; // At second_last
        temp->next = NULL;
        delete (temp2);
    }

    void deleteatpos(int pos)
    {
        temp = head;
        int current_pos = 0;
        while (current_pos != pos - 1)
        {
            temp = temp->next;
            current_pos++;
        }
        node *temp2 = temp->next; // Storing address of node which has to be deleted
        temp->next = temp->next->next;
        delete (temp2);
    }

    void deleteatdata(int x)
    {
        temp = head;
        while (temp->next->data != x)
        {
            temp = temp->next;
        }
        // temp at pos-1
        node *temp2 = temp->next; // Storing address of node which has to be deleted
        temp->next = temp->next->next;
        delete (temp2);
    }

    void searchdata(int x)
    {
        temp = head;
        int position = 0;
        while (temp != NULL)
        {
            if (temp->data == x)
            {
                cout << "Value " << x << " found at position " << position << " in the list." << endl;
                return;
            }
            temp = temp->next;
            position++;
        }
        cout << "Value " << x << " not found in the list." << endl;
    }

    void reverse()
    {
        if (head == NULL || head->next == NULL)
        {
            return;
        }
        node *previous = NULL;
        node *Current = head;
        node *Next_node = NULL;
        while (Current != NULL)
        {
            Next_node = Current->next;
            Current->next = previous;
            previous = Current;
            Current = Next_node;
        }
        head = previous;
    }

    void concatenate(linkedlist &l2)
    {
        if (head == NULL)
        {
            head = l2.head;
            return;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = l2.head;
        }
    }

    void sort()
    {
        if (head == NULL)
        {
            cout << "List is empty. Nothing to sort." << endl;
            return;
        }
        node *current, *index;
        int tempValue;

        for (current = head; current != NULL; current = current->next)
        {
            for (index = current->next; index != NULL; index = index->next)
            {
                if (current->data > index->data)
                {
                    tempValue = current->data;
                    current->data = index->data;
                    index->data = tempValue;
                }
            }
        }
    }

    void deleteduplicate()
    {
        node *curr_node = head;
        while (curr_node != NULL)
        {
            while ((curr_node->next != NULL) && (curr_node->data == curr_node->next->data))
            {
                temp = curr_node->next; // node to be deleted
                curr_node->next = curr_node->next->next;
                delete (temp);
            }
            // this loop ends when current node and next node values are different
            // or ll ends
            curr_node = curr_node->next;
        }
    }

    void intersection(linkedlist &l2)
    {
        linkedlist result;
        node *current1 = this->head;
        node *current2 = l2.head;
        while (current1 != NULL && current2 != NULL)
        {
            if (current2->data < current1->data)
            {

                current2 = current2->next;
            }
            else if (current1->data < current2->data)
            {

                current1 = current1->next;
            }
            else
            {
                result.insertattail(current1->data);
                current1 = current1->next;
                current2 = current2->next;
            }
        }
        result.print();
    }
};

int main()
{
    linkedlist l1, l2, unionlist1, unionlist2, interlist1, interlist2;
    int choice;
start:
    do
    {
        cout << "\n******************************************* SINGLY LINKED LIST *******************************************" << endl;
        cout << "0.   Create" << endl;
        cout << "1.   Insert at head" << endl;
        cout << "2.   Insert at tail" << endl;
        cout << "3.   Insert at Position" << endl;
        cout << "4.   Insert at data" << endl;

        cout << "5.   Update at head" << endl;
        cout << "6.   Update at tail" << endl;
        cout << "7.   Update at Position" << endl;
        cout << "8.   Update at data" << endl;

        cout << "9.   Delete at head" << endl;
        cout << "10.  Delete at tail" << endl;
        cout << "11.  Delete at Position" << endl;
        cout << "12.  Delete at data" << endl;

        cout << "13.  Search data" << endl;
        cout << "14.  Reverse" << endl;

        cout << "15.  Create list2 for concatenation" << endl;
        cout << "16.  Concatenate list1 and list2" << endl;
        cout << "17.  Sort" << endl;

        cout << "18.  Create 2 lists for Union" << endl;
        cout << "19.  Union" << endl;
        cout << "20.  Create 2 lists for Intersection" << endl;
        cout << "21.  Intersection" << endl;

        cout << "99.  Print" << endl;
        cout << "100. Exit" << endl;
        cout << "**********************************************************************************************************" << endl;
        cout << "Enter Choice: ";
        cin >> choice;
        if (choice == 0)
        {
            l1.create();
        }
        else if (choice == 1)
        {
            int x;
            cout << "Enter Value which u want to insert" << endl;
            cin >> x;
            l1.insertathead(x);
        }
        else if (choice == 2)
        {
            int x;
            cout << "Enter Value which u want to insert" << endl;
            cin >> x;
            l1.insertattail(x);
        }
        else if (choice == 3)
        {
            int x, y;
            cout << "Enter Value which u want to insert" << endl;
            cin >> x;
            cout << "Enter Position where u want to insert" << endl;
            cin >> y;
            l1.insertatpos(x, y);
        }
        else if (choice == 4)
        {
            int x, y;
            cout << "Enter Value which u want to insert" << endl;
            cin >> x;
            cout << "Enter Data where u want to insert" << endl;
            cin >> y;
            l1.insertatdata(x, y);
        }

        else if (choice == 5)
        {
            int x;
            cout << "Enter Value which u want to update" << endl;
            cin >> x;
            l1.updateathead(x);
        }
        else if (choice == 6)
        {
            int x;
            cout << "Enter Value which u want to update" << endl;
            cin >> x;
            l1.updateattail(x);
        }
        else if (choice == 7)
        {
            int x, y;
            cout << "Enter Value which u want to update" << endl;
            cin >> x;
            cout << "Enter Position where u want to update" << endl;
            cin >> y;
            l1.updateatpos(x, y);
        }
        else if (choice == 8)
        {
            int x, y;
            cout << "Enter Value which u want to update" << endl;
            cin >> x;
            cout << "Enter Data where u want to update" << endl;
            cin >> y;
            l1.updateatdata(x, y);
        }

        else if (choice == 9)
        {
            l1.deleteathead();
            cout << "Deleted\n";
        }
        else if (choice == 10)
        {
            l1.deleteattail();
            cout << "Deleted\n";
        }
        else if (choice == 11)
        {
            int x;
            cout << "Enter Position on which u want to delete" << endl;
            cin >> x;
            l1.deleteatpos(x);
        }
        else if (choice == 12)
        {
            int x;
            cout << "Enter Data which u want to delete" << endl;
            cin >> x;
            l1.deleteatdata(x);
        }

        else if (choice == 13)
        {
            int x;
            cout << "Enter Data to search" << endl;
            cin >> x;
            l1.searchdata(x);
        }
        else if (choice == 14)
        {
            l1.reverse();
        }
        else if (choice == 15)
        {
            l2.create();
            l2.print();
        }
        else if (choice == 16)
        {
            l1.concatenate(l2);
        }

        else if (choice == 17)
        {
            l1.sort();
        }

        else if (choice == 18)
        {
            unionlist1.create();
            unionlist2.create();
        }
        else if (choice == 19)
        {
            unionlist1.concatenate(unionlist2);
            unionlist1.sort();
            unionlist1.deleteduplicate();
            unionlist1.print();
        }

        else if (choice == 20)
        {
            interlist1.create();
            interlist2.create();
        }
        else if (choice == 21)
        {
            interlist1.intersection(interlist2);
        }

        else if (choice == 99)
        {
            l1.print();
            cout << endl;
        }
        else if (choice == 100)
        {
            cout << "Exiting" << endl;
        }
        else
        {
            cout << "Invalid Option" << endl;
            goto start;
        }
    } while (choice != 100);
    return 0;
}