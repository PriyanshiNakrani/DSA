#include<iostream>
using namespace std;

class node
{
    public:
    node *left;
    int data;
    node *right;
};

void insert(node** head_ref,int value)
{
    node* temp=*head_ref;
    node* temp_fol=temp;
    node* new_node=new node;
    new_node->data=value;
    new_node->left=0;
    new_node->right=0;
    
    if(*head_ref==0)
    {
        *head_ref=new_node;
    }
    else
    {
        while(1)
        {
            temp_fol=temp;
            if(temp->data>value)
            {
                temp=temp->left;
            }
            else
            {
                temp=temp->right;
            }
            if(temp==0)
            {
                break;
            }
        }
        if(value<temp_fol->data)
        {
            temp_fol->left=new_node;
        }
        else
        {
            temp_fol->right=new_node;
        }
    }
}
void inorder(node* head)
{
    if(head!=0)
    {
        inorder(head->left);
        cout<<head->data<<"->";
        inorder(head->right);
    }
}
void preorder(node* head)
{
    if(head!=0)
    {
        cout<<head->data<<"->";
        preorder(head->left);
        preorder(head->right);
    }
}
void postorder(node* head)
{
    if(head!=0)
    {
        postorder(head->left);
        postorder(head->right);
        cout<<head->data<<"->";
    }
}
int main()
{
    node* head=0;
    int x=0;
    while(1)
    {
        cout<<"Enter Data: "<<endl;
        cin>>x;
        if(x==-1)
        {
            break;
        }
        insert(&head,x);
    }
    
    cout<<"Inorder : ";
    inorder(head);
    cout<<endl;
    
    cout<<"Preorder : ";
    preorder(head);
    cout<<endl;
    
    cout<<"Postorder : ";
    postorder(head);
    cout<<endl;
}