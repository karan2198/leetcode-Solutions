//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  int solve(string A,int n,int i, int j,vector<vector<int>> &dp){
      if(i==j) return 1;
      if(i>j) return 0;
      if(dp[i][j] != -1) return  dp[i][j];
      if(A[i] == A[j]) return  dp[i][j] =  (2 + solve(A,n,i+1,j-1,dp));
      
      int a = solve(A,n,i+1,j,dp);
      int b = solve(A,n,i,j-1,dp);
      
      return dp[i][j] = max(a,b);
  }
    int longestPalinSubseq(string A) {
        //code here
        int n = A.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        return solve(A,n,0,n-1,dp);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends