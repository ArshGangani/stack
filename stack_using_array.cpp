#include<iostream>
using namespace std;

class stack
{
    public:
    int* arr;
    int size;
    int top;
    stack(int size)
    { 
        this->size=size;
        arr = new int[size];
        this->top=-1;
    }
    void push(int value)
    {
        if(size-top>1)
        {
            top++;
            arr[top]=value;
        }
        else
        {
            cout << "Stack Overflow\n";
        }
    }
    int pop()
    {
        if(top<0)
        {
            cout << "Stack underflow\n";
            return -1;
        }
        return arr[top--];
    }
    int tops()
    {
        return arr[top];
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