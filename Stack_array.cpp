//stack in array

#include<iostream>
using namespace std;
#define N 3

int stack[N];
int top=-1;

void push()
{
    int x;
    cout<<"Enter data:";
    cin>>x;
    if(top==N-1)
    {
        cout<<"Overflow"<<endl;
    }
    else
    {
        top++;
        stack[top]=x;
    }
}

void pop()
{
    int x;
    if(top==-1)
    {
        cout<<"Underflow"<<endl;
    }
    else
    {
        x=stack[top];
        top--;
        cout<<"Pop value is "<<x<<endl;
    }
}

void peek()
{
    if(top==-1)
    {
        cout<<"stack is empty"<<endl;
    }
    else
    {
        cout<<"Top most value is "<<stack[top]<<endl;
    }
}

void display()
{
    if(top==-1)
    {
        cout<<"stack is empty"<<endl;
    }
    else
    {
        for(int i=top;i>=0;i--)
        {
            cout<<"Stack value is "<<stack[i]<<"-------"<<endl;
        }
        cout<<endl;
    }
}

int main()
{
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
                push();
                break;
                
            case 2:
                pop();
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