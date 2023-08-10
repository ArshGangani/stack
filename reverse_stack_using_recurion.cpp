#include<iostream>
#include<stack>
using namespace std;

void reverse(stack<int> &stack,int num1)
{
	if(stack.empty() || num1>=stack.top())
	{
		stack.push(num1);
		return;
	}
	int num2 = stack.top();
	stack.pop();
	reverse(stack,num1);
	stack.push(num2);
}

void solve(stack<int> &stack)
{
	if(stack.empty())
	{
		return;
	}
	int n = stack.top();
	stack.pop();
	solve(stack);
	reverse(stack,n);
}

void sortStack(stack<int> &stack)
{
	// Write your code here
	solve(stack);
}

int main()
{
    stack<int> s1;
    s1.push(20);
    s1.push(10);

    s1.push(-1);
    s1.push(100);
    s1.push(50);
    s1.push(0);
    solve(s1);
    for(int i=0;i<6;i++)
    {
        cout << s1.top() << " ";
        s1.pop();
    }
    return 0;
}