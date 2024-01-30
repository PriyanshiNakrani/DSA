//queue using linkedlist

#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node* front=0;
Node* rear=0;

void enqueue(int x)
{
    Node* newnode=new Node;
    newnode->data=x;
    newnode->next=0;
    if(front==0&&rear==0)
    {
        front=rear=newnode;
        cout<<newnode->data<<endl;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
        cout<<newnode->data<<endl;
    }
}

void dequeue()
{
    if(front==0&&rear==0)
    {
        cout<<"Underflow"<<endl;
        
    }
    else
    {
        Node* temp=front;
        cout<<temp->data<<endl;
        front=front->next;
        delete temp;
    }
}

void display()
{
    Node* temp=front;
    if(front==0)
    {
        cout<<"Queue is Empty"<<endl;
        
    }
    else
    {
        cout<<"The Queue element are: "<<endl;
        while(temp!=0)
        {
            cout<<temp->data<<endl;
            temp=temp->next;
        }
    }
}

void peek()
{
    if(front==0)
    {
        cout<<"Queue is empty"<<endl;
        
    }
    else
    {
        cout<<front->data<<endl;
        
    }
}

int main()
{
     
    int choice,x;
    
    do{
        cout<<"Menu:"<<endl;
        cout<<"1.enqueue"<<endl;
        cout<<"2.Dequeue"<<endl;
        cout<<"3.Peek in Queue"<<endl;
        cout<<"4.Display Queue"<<endl;
        cout<<"5.exit"<<endl;
        cout<<"Enter your choice: "<<endl;
        cin>>choice;
        
        switch(choice)
        {
            case 1:
                cout<<"Enter data: "<<endl;
                cin>>x;
                enqueue(x);
                break;
                
            case 2:
                dequeue();
                break;
                
            case 3:
                peek();
                break;
                
            case 4:
                display();
                break;
                
            case 5:
                cout<<"Exiting the program"<<endl;
                break;
                
            default:
                cout<<"Invalid choice...please enter the valid choice"<<endl;
                break;
        }
        
    }while(choice!=5);
}
