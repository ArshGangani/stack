//next smaller element
#include<iostream>
#include<stack>
using namespace std;

void solve(int arr[],int size)
{
    stack<int> s1;
    int arr1[size],k=0;
    for(int i=size-1;i>=0;i--)
    {
        if(s1.empty())
        {
            s1.push(arr[i]);
            arr1[k]=-1;
            k++;
        }
        else
        {
            while(!s1.empty() && (s1.top()>=arr[i]))
            {
                s1.pop();
            }
            if(s1.empty())
            {
                arr1[k]=-1;
                k++;
            }
            else
            {
                arr1[k]=s1.top();
                k++;
            }
            s1.push(arr[i]);
        }
    }
    for(int i=size-1;i>=0;i--)
    {
        cout << arr1[i] << endl;
    }
}

int main()
{
    int arr[]={5,4,6,3,7};
    solve(arr,5);
    return 0;
}