class Solution {
public:
    int find_next(vector<vector<int>>& events,int i){
        int endTime = events[i][1];
        int l = i+1,r = events.size() - 1;
        
        int pos = -1;
        
        while(l <= r) {
            int mid = (l+r)/2;
            if(events[mid][0]>endTime){
                pos = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        
        return pos;
    }
    int helper(vector<vector<int>>& events,int i,int k,vector<vector<int>> &dp){
        if(i>=events.size() || k==0 || i == -1) return 0;
        if(dp[i][k] != -1)  return dp[i][k];
        int not_tack = helper(events, i+1,k, dp);
        int j = find_next(events,i);
        int tack = events[i][2] + helper(events,j,k-1,dp);
        
        return dp[i][k] = max(tack,not_tack);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        vector<vector<int>> dp(events.size(), vector<int> (k+1,-1));
        return helper(events,0,k,dp);
    }
};