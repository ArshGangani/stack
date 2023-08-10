#include<iostream>
#include<stack>
using namespace std;

bool findRedundantBrackets(string &s)
{
    // Write your code here.
    int len = s.length();
    stack<char> s1;
    bool check;
    for(int i=0;i<len;i++)
    {
        if(s[i]=='(' || s[i]=='+' || s[i]=='-' || s[i]=='/' || s[i]=='*')
            s1.push(s[i]);
        else
        {
            if(s[i]==')')
            {
                bool check = true;
                while(s1.top()!='(')
                {
                    char top = s1.top();
                    if(top=='+' || top=='-' || top=='*' || top=='/')
                    {
                        check=false;
                    }
                    s1.pop();
                }
                if(check==true)
                    return true;
                s1.pop();        

            }
        }
    }
    return false;
}
int main()
{
    
}