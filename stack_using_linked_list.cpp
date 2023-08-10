#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    node(int data)
    {
        this->data=data;
        this->next = NULL;
    }
};

class stack
{
    public:
    node* head;
    int top;
    int size;
    stack(int size)
    {
        this->top = -1;
        this->size = size;
    }
    void push(int data)
    {
        if(size-top>1)
        {
            top++;
            node* newnode = new node(data);
            newnode->next = head;
            head = newnode;
        }
        else
        {
            cout << "StackOverflow\n";
        }
    }
    int pop()
    {
        if(head==NULL)
        {
            cout << "Stack underflow\n";
            return -1;
        }
        else
        {
            top--;
            node* temp = head;
            head=head->next;
            temp->next=NULL;
            return temp->data;
        }
    }
    int tops()
    {
        if(head==NULL)
        {
            cout << "Stack underflow\n";
            return -1;
        }
        else
        {
            return head->data;
        }
    }
    bool isEmpty()
    {
        if(top==-1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};

int main()
{
    stack s1(5);
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    //s1.push(60);
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    cout << s1.tops() << endl;
    if(s1.isEmpty())
    {
        cout << "Stack is empty\n";
    }
    else
    {
        cout << "Stack is not empty\n";
    }
    return 0;
}