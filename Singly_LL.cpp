#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void insertAtBegining(Node* &head,int data)
{
    Node* newnode=new Node;
    newnode->data=data;
    newnode->next=head;
    head=newnode;
}

void insertAtEnding(Node* &head,int data)
{
    Node* newnode=new Node;
    newnode->data=data;
    newnode->next=0;
    if(head==0)
    {
        head=newnode;
        return;
    }
    Node* temp=head;
    while(temp->next!=0)
    {
        temp=temp->next;
    }
    temp->next=newnode;
}

void insertAfterPosition(Node* &head,int pos,int data)
{
    Node* temp=head;
    int i=1;
    while(i<pos && temp!=0)
    {
        temp=temp->next;
        i++;
    }
    if(temp==0)
    {
        cout<<"Invalid Position"<<endl;
    }
    else
    {
        Node *newnode=new Node;
        newnode->data=data;
        newnode->next=temp->next;
        temp->next=newnode;
    }
}
void insertBeforePosition(Node*& head,int pos,int data)
{
    if(pos<=1)
    {
        insertAtBegining(head,data);
    }
    
    Node* temp=head;
    Node* prev=0;
    int i=1;
    while(i<pos && temp!=0)
    {
        prev=temp;
        temp=temp->next;
        i++;
    }
    if(temp==0)
    {
        cout<<"Invalid Position"<<endl;
    }
    else
    {
        Node* newnode=new Node;
        newnode->data=data;
        newnode->next=temp;
        prev->next=newnode;
    }
}

void DeleteAtBegining(Node* &head)
{
    if(head==0)
    {
        cout<<"Linked list Empty"<<endl;
    }
    else
    {
        Node* temp=head;
        head=head->next;
        delete temp;
        cout<<"Delete first node successfully"<<endl;
    }
}

void deleteAtEnding(Node* &head)
{
    if(head==0)
    {
        cout<<"Linked list is empty"<<endl;
    }
    Node* temp=head;
    Node* prev=0;
    while(temp->next!=0)
    {
        prev=temp;
        temp=temp->next;
    }
    if(prev==0)
    {
        delete temp;
        head=0;
    }
    else
    {
        prev->next=0;
        delete temp;
    }
    cout<<"delete last node successfully"<<endl;
    
}

void deleteAtPosition(Node* &head,int pos)
{
    if(head==0 || pos<=0)
    {
        cout<<"Invalid Position"<<endl;
    }
    else
    {
        Node *nextnode;
        int i=1;
        Node* temp=head;
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        if(temp == 0 || temp->next == 0)
        {
            cout << "Invalid Position" << endl;
        }
        else
        {
        nextnode=temp->next;
        temp->next=nextnode->next;
        delete nextnode;
        cout<<"delete node at position "<<pos<<" successfully"<<endl;
    
        }
    }
}
void display(Node*head)
{
    while(head!=0)
    {
        cout<<"["<<head->data<<"]"<<((head->next==0)?"->[0]":"->");
        head=head->next;
    }
    cout<<endl;
}

int main()
{
    int data,choice,pos;
    Node* head=0;
    
    do{
        cout<<"Menu:\n";
        cout<<"1.insert at begining\n";
        cout<<"2.insert at ending\n";
        cout<<"3.insert after position\n";
        cout<<"4.insert before position\n";
        cout<<"5.delete at begining\n";
        cout<<"6.delete at ending\n";
        cout<<"7.delete node at position\n";
        cout<<"8.display linked list\n";
        cout<<"9.Exit\n";
        cout<<"enter your choice\n";
        cin>>choice;
        
        switch(choice)
        {
            case 1:
                cout<<"Enter Data\n";
                cin>>data;
                insertAtBegining(head,data);
                break;
            case 2:
                cout<<"Enter Data\n";
                cin>>data;
                insertAtEnding(head,data);
                break;
            case 3:
                cout<<"Enter position:";
                cin>>pos;
                cout<<"Enter Data\n";
                cin>>data;
                insertAfterPosition(head,pos,data);
                break;
            case 4:
                cout<<"Enter position:";
                cin>>pos;
                cout<<"Enter Data\n";
                cin>>data;
                insertBeforePosition(head,pos,data);
                break;
            case 5:
                DeleteAtBegining(head);
                break;
            case 6:
                deleteAtEnding(head);
                break;
            case 7:
                cout<<"Enter position:";
                cin>>pos;
                deleteAtPosition(head,pos);
                break;
            case 8:
                display(head);
                break;
            case 9:
                cout<<"Exiting the program\n";
                break;
            default:
                cout<<"Invalid choice...\n";
        }
    }while(choice!=9);
    return 0;
}