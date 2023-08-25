class Solution {
public:
  bool helper(int i,int j,int k,string &s1, string &s2, string &s3,vector<vector<int>> &dp){
        if(i<0 && j<0 && k<0)
            return true;

        if(dp[i+1][j+1]!=-1)
            return dp[i+1][j+1];
        
        bool result = false;
        if(i>=0 && j>=0 && k>=0 && s1[i]==s3[k] && s2[j]==s3[k])
            return result = helper(i-1,j,k-1,s1,s2,s3,dp) || helper(i,j-1,k-1,s1,s2,s3,dp) ;
        else if (i>=0 && k>=0 && s1[i]==s3[k])
            return result = helper(i-1,j,k-1,s1,s2,s3,dp);
        else if(j>=0 && k>=0 && s2[j] == s3[k] )
            return result = helper(i,j-1,k-1,s1,s2,s3,dp);
        
        return dp[i+1][j+1] = result;
    }
    bool isInterleave(string &s1, string &s2, string &s3) {
        if(s1.length() + s2.length() != s3.length())
            return false;
        vector<vector<int>> dp(s1.length()+1,vector<int>(s2.length()+1,-1));
        return helper(s1.length()-1,s2.length()-1,s3.length()-1,s1,s2,s3,dp);
    }
};