//stack using linked list

#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* push(Node* top)
{
    Node* newnode=new Node;
    cout<<"Enter data: ";
    cin>>newnode->data;
    newnode->next=top;
    top=newnode;
    return top;
}

Node* pop(Node* top)
{
    if(top==0)
    {
        cout<<"Overflow"<<endl;
    }
    else
    {
        Node* temp=top;
        cout<<"pop is "<<top->data<<endl;
        top=top->next;
        delete temp;
    }
    return top;
}

Node* peek(Node* top)
{
    if(top==0)
    {
        cout<<"Stack is empty"<<endl;
    
    }
    else
    {
        cout<<"top most element is "<<top->data<<endl;
    }
    return top;
}

Node* display(Node* top)
{
    Node* temp=top;
    if(top==0)
    {
        cout<<"Stack is empty"<<endl;
    }
    else
    {
        cout<<"Stack element are: "<<endl;
        while(temp!=0)
        {
            cout<<temp->data<<endl;
            temp=temp->next;
        }
    }
    return top;
}

int main()
{
    Node* top=0;
    int choice;
    do{
        
        cout<<"Menu:"<<endl;
        cout<<"1.Push in stack"<<endl;
        cout<<"2.Pop in stack"<<endl;
        cout<<"3.Peek in stack"<<endl;
        cout<<"4.Display stack"<<endl;
        cout<<"5.exit"<<endl;
        cout<<"Enter your choice: "<<endl;
        cin>>choice;
        
        switch(choice)
        {
            case 1:
                top=push(top);
                break;
                
            case 2:
                top=pop(top);
                break;
                
            case 3:
                top=peek(top);
                break;
                
            case 4:
                top=display(top);
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