//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxOnes(int a[], int n)
    {
          int r=0;
        int count=0;
        int flip=0;
        while(r<n){
            if(a[r]==0){
                count++;
            }else{
                count--;
            }
            
            flip=max(flip,count);
            
            if(count<0){
                count=0;
            }
            
            r++;
        }
        
        for(int i=0;i<n;i++){
            if(a[i]==1) flip++;
        }
        return flip;
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends