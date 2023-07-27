// Online C++ compiler to run C++ program online
// Online C++ compiler to run C++ program online
// #include<stdio.h>
#include<iostream>
using namespace std;

class Hotel{
    private:
        struct Node
        {
            int id,date;
            string name,roomtype;
            Node* next;
        };
    public:
        Node* head = NULL ;    
        void menu();
        void insert();
        void search();
        void update();
        void del();
        void show(); 
        void sort(); 
};

void Hotel:: menu()
{
    int choice ;
    cout<<"\n";
    cout<<"\tWelcome To Hotel Management System Application" <<endl;
    cout<<"\n\t_______Hotel Management System________";
    cout<<"\n\nS.No \t\t Functions\t\t\t\tDescription"<<endl;
    cout<<"\n1\t\t\t Allocate Room\t\t\tInsert New Room";
    cout<<"\n2\t\t\t Search Room\t\t\tSearch Room with RoomID";
    cout<<"\n3\t\t\t Update Room\t\t\tUpdate Room Record";
    cout<<"\n4\t\t\t Delete Room\t\t\tDelete Room with RoomID";
    cout<<"\n5\t\t\t Show Room Records\t\tShow Room Records that (we Added)";
    cout<<"\n6\t\t\t Exit"<<endl;

    cout<<"Enter Your Choice: ";
    cin>>choice;
    switch(choice)
    {
        case 1:
            insert();
            menu();
            break;
        case 2:
            search();
            menu();
            break;
        case 3:
            update();
            menu();
            break;
        case 4:
            del();
            menu();
            break;
        case 5:
            show();
            menu();
            break;
        case 6:
            exit(0);
        default:
            cout<<"Invalid";    
    }

}
void Hotel :: insert()
{
    cout<<"\n\t_______Hotel Management System________";
    Node *new_node = new Node;
    cout<<"\nEnter Room ID: ";
    cin>>new_node->id;
    cout<<"\nEnter Customer Name: ";
    cin>>new_node->name;
    cout<<"\nEnter Allocated Date: ";
    cin>>new_node->date;
    cout<<"\nEnter Room Type(single/double/twin): ";
    cin>>new_node->roomtype;

    if(head == NULL )
    {
        head = new_node;
    }
    else
    {
        Node* ptr = head;
        while(ptr ->next != NULL)
        {
            ptr= ptr->next;
        }
        ptr->next = new_node;
    }
    cout<<"\n\n***************Record inserted Successfully***************\n\n";
}
void Hotel :: search()
{
    cout<<"\n\t_____________Hotel Management System_______________";
    int t_id;
    cout<<"\nEnter Room ID: ";
    cin>>t_id;

    if(head == NULL )
    {
        cout<<"\nThere is no room with RoomID: "<<t_id<<endl;
    }
    else
    {
        Node *ptr=head;
        while(ptr != NULL)
        {
            if(ptr->id == t_id)
            {
                cout<<"\n************************************************";
                cout<<"\n\nRoom ID: "<<ptr->id;
                cout<<"\n\nCustomer Name: "<<ptr->name;
                cout<<"\n\nAllocated Date: "<<ptr->date;
                cout<<"\n\nRoom Type: "<<ptr->roomtype;
                cout<<"\n\n************************************************\n\n";

                break;
            }
            ptr=ptr->next;
        }

        if(ptr == NULL){
             cout<<"\nThere is no room with RoomID: "<<t_id<<endl;
        }
    }
}
void Hotel :: update()
{
    cout<<"\n\t_______Hotel Management System________";
    int t_id;
    cout<<"\nEnter Room ID: ";
    cin>>t_id;

    if(head == NULL )
    {
        cout<<"\nInvalid RoomID"<<endl;
    }
    else
    {
        Node *ptr=head;
        while(ptr != NULL)
        {
            if(ptr->id == t_id)
            {
                cout<<"\n***************Enter Updated Record***************";

                cout<<"\n\nRoom ID: ";
                cin>>ptr->id;
                cout<<"\nCustomer Name: ";
                cin>>ptr->name;
                cout<<"\nAllocated Date: ";cin>>ptr->date;
                cout<<"\nRoom Type: "; cin>>ptr->roomtype;

                cout<<"\n***************Record Updated successfully***************";
                break;
            }
            ptr=ptr->next;
        }
        if(ptr == NULL){
             cout<<"\nInvalid RoomID "<<endl;
        }
    }
}

void Hotel :: del()
{
    cout<<"\n\t_______Hotel Management System________";
    int t_id;
    cout<<"\nEnter Room ID: ";
    cin>>t_id;

    if(head == NULL )
    {
        cout<<"\nInvalid RoomID"<<endl;
    }
    else
    {
        Node *prev=NULL, *curr=head;
        if(curr->id == t_id)
        {
            head=head->next;
        }
        else{
            while(curr != NULL)
            {
                if(curr->id == t_id)
                {
                    prev->next=curr->next;
                    break;
                }
                prev=curr;
                curr=curr->next;
            }
        }
        if(curr == NULL){
             cout<<"\nInvalid RoomID "<<endl;
        }
        else
        {
            delete curr;
            cout<<"\n***************Record Deleted successfully***************";
        }
    }
}


void Hotel:: show()
{
    // sort();
    if(head==NULL){
        cout<<"\n***************There is no Room booked in Hotel***************"<<endl;
    }
    Node *ptr=head;
    while(ptr)
    {
        cout<<"\n************************************************";
        cout<<"\n\nRoom ID: "<<ptr->id;
        cout<<"\n\nCustomer Name: "<<ptr->name;
        cout<<"\n\nAllocated Date: "<<ptr->date;
        cout<<"\n\nRoom Type: "<<ptr->roomtype;
        cout<<"\n\n************************************************\n\n";
        
        ptr=ptr->next ;
    }
}

void Hotel:: sort()
{

    int count=0;
    int t_id, t_date;
    string t_name, t_roomtype;
    Node *ptr=head;
    while(ptr)
    {
        count++ ;
        ptr=ptr->next;
    }

    for(int i=1;i<count;i++)
    {
        ptr=head;
        for(int j=1;j<count;j++)
        {
            if(ptr->id > ptr->next->id)
            {
                //saving current data into temp node;
                t_id=ptr->id;
                t_date=ptr->date;
                t_name=ptr->name;
                t_roomtype=ptr->roomtype;

                //
                ptr->id = ptr->next->id;
                ptr->date= ptr->next->date;
                ptr->name = ptr->next->name;
                ptr->roomtype = ptr->next->roomtype;

                //

                ptr->next->id= t_id;
                ptr->next->date= t_date;
                ptr->next->name= t_name;
                ptr->next->roomtype= t_roomtype;
            }
        }
    }
}

int main()
{
    Hotel obj;
    obj.menu();
    return 0;
}