//queue using array

#include<iostream>
using namespace std;
#define N 3

int queue[N];
int front=-1;
int rear=-1;

void enqueue()
{
    int data;
    cout<<"Enter data"<<endl;
    cin>>data;
    if(rear==N)
    {
        cout<<"Overflow"<<endl;
    }
    else
    {
        if(front==-1)
        {
            front=0;
        }
        rear++;
        queue[rear]=data;
        cout<<"Queue element are "<<data<<endl;
    }
}

void qequeue()
{
    if(front==-1 && rear==-1)
    {
        cout<<"Underflow"<<endl;
    }
    else if(front==rear)
    {
        front=rear=-1;
    }
    else
    {
        cout<<"dequeue element is "<<queue[front]<<endl;
        front++;
    }
}

void peek()
{
    if(front==-1 && rear==-1)
    {
        cout<<"Empty queue"<<endl;
    }
    else
    {
        cout<<"first element is "<<queue[front]<<endl;
    }
}

void display()
{
    if(front==-1 && rear==-1)
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        for(int i=front;i<rear+1;i++)
        {
            cout<<queue[i]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    
    int choice;
    
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
                enqueue();
                break;
                
            case 2:
                qequeue();
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
}