#include<iostream>
#include<string>
#include<stack>
using namespace std;

int check_precedence(char temp)
{
    if(temp=='+' || temp=='-')
    {
        return 1;
    }
    else if(temp=='*' || temp=='/')
    {
        return 2;
    }
    else if(temp=='^')
    {
        cout << "     ";
        return 3;
    }
    else
    {
        return -1;
    }
}

void postfix(string s)
{
    stack<char> s1;
    string postfix;
    string reverse=s;
    int k=0;
    for(int i = int(s.length())-1;i>=0;i--)
    {
        reverse[k]=s[i];
        if(reverse[k]==')'){reverse[k]='(';}
        else if(reverse[k]=='('){reverse[k]=')';}
        k++;
    }
    cout << reverse << endl;
    int length = int(reverse.length());
    for(int i=0;i<length;i++)
    {
        if((reverse[i] >= 'a' && reverse[i] <= 'z') || (reverse[i]>='A' && reverse[i]<='Z') || (reverse[i]>='0' && reverse[i]<='9'))
        {
            postfix+=reverse[i];
        }
        else if(reverse[i]=='(')
        {
            s1.push('(');
        }
        else if(reverse[i]==')')
        {
            while(s1.top()!='(')
            {
                postfix+=s1.top();
                s1.pop();
            }
            s1.pop();
        }
        else if(reverse[i]=='^')
            s1.push(reverse[i]);
        else
        {
            while(!s1.empty() && check_precedence(reverse[i]) <= check_precedence(s1.top()))
            {
                postfix+=s1.top();
                s1.pop();
            }
            //cout << reverse[i] << " ";
            s1.push(reverse[i]);
        }
    }
    while(!s1.empty())
    {
        postfix+=s1.top();
        s1.pop();
    }

    cout << postfix << endl;
}

int main()
{
    string s;
    cin >> s;
    postfix(s);
    return 0;
}