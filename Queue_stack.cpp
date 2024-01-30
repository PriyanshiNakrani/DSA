#include<iostream>
using namespace std;

#define N 5
int s1[N],s2[N];
int top1=-1,top2=-1;
int count=0;

void push1(int a)
{
    if(top1==N-1)
    {
        cout<<"Queue is full"<<endl;
    }
    else
    {
        top1++;
        s1[top1]=a;
    }
}
void push2(int a)
{
    if(top1==N-1)
    {
        cout<<"Queue is full"<<endl;
    }
    else
    {
        top2++;
        s2[top2]=a;
    }
}
int pop1()
{
    return s1[top1--];
}
int pop2()
{
    return s2[top2--];
}
void enqueue()
{
    int data;
    if(top1==N-1)
    {
        cout<<"Overflow"<<endl;
    }
    else
    {
        cout<<"Enter the data: "<<endl;
        cin>>data;
        push1(data);
        count++;
    }
}
void dequeue()
{
    int i;
    int a;
    int b;
    int x;
    if (top1 == -1)
    {
        cout << "The queue is empty" << endl;
    }
    else
    {
        for (i = 0; i < count; i++)
        {
            a = pop1();
            push2(a);
        }
        b = pop2();
        cout << "The dequeued element is: " << b << endl;
        count--;
        for (i = 0; i < count; i++)
        {
            x = pop2();
            push1(x);
        }
    }
}
void display()
{
    int i;
    if(top1==-1)
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        for(int i=0;i<=top1;i++)
        {
            cout<<s1[i]<<"\t";
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
        cout<<"3.Display Queue"<<endl;
        cout<<"4.exit"<<endl;
        cout<<"Enter your choice: "<<endl;
        cin>>choice;
        
        switch(choice)
        {
            case 1:
                enqueue();
                break;
                
            case 2:
                dequeue();
                break;
                
            
            case 3:
                display();
                break;
                
            case 4:
                cout<<"Exiting the program"<<endl;
                break;
                
            default:
                cout<<"Invalid choice...please enter the valid choice"<<endl;
                break;
        }
        
    }while(choice!=5);

}
}