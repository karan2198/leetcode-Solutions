//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here.. 
         vector<int> a;
        int mid;
        (sizeOfStack%2)?mid=sizeOfStack/2:mid=sizeOfStack/2-1;
        for(int i=sizeOfStack-1;i>=0;i--){
            if(i==mid) {
                s.pop();
                continue;}
            a.push_back(s.top());
            s.pop();
        }
        for(int i=a.size()-1;i>=0;i--){
            s.push(a[i]);
            a.pop_back();
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends