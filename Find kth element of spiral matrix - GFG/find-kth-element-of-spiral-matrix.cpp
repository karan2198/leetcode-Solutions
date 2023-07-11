//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		// Your code goes here.
 		
 		int rowSt=0,colSt=0,rowEnd=n-1,colEnd=m-1;
	    
	    
	    while(rowSt<=rowEnd && colSt<=colEnd)
	    {
	        for(int i=colSt;i<=colEnd;i++)
	        {
	            k-=1;
	            if(k==0) return a[rowSt][i];
	        }
	        
	        rowSt+=1;
	        
	        for(int i=rowSt;i<=rowEnd;i++)
	        {
	            k-=1;
	            if(k==0)  return a[i][colEnd];
	        }
	        
	        colEnd-=1;
	        
	        for(int i=colEnd;i>=colSt;i--)
	        {
	            k-=1;
	            if(k==0) return a[rowEnd][i];
	        }
	        
	        rowEnd-=1;
	        
	        for(int i=rowEnd;i>=rowSt;i--)
	        {
	            k-=1;
	            if(k==0) return a[i][colSt];
	        }
	        
	        colSt+=1;
	    }
	    
	    return -1;
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends