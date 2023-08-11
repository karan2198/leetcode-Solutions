class Solution {
public:
     int solve(int i,int curSum,vector<int>& coins,int N,int sum,vector<vector<int>>& dp)
    {
        if(curSum==sum) return 1L;
        if(i==N) return 0L;
        
        if(dp[i][curSum]!=-1) return dp[i][curSum];
        
        if(curSum+coins[i]<=sum)
            return dp[i][curSum]=solve(i+1,curSum,coins,N,sum,dp) + solve(i,curSum+coins[i],coins,N,sum,dp);
            
        return dp[i][curSum]=solve(i+1,curSum,coins,N,sum,dp);
    }
    int change(int amount, vector<int>& coins) {
         int N = coins.size();
         vector<vector<int>> dp(N,vector<int>(amount,-1));

        return solve(0,0,coins,N,amount,dp);
    }
};