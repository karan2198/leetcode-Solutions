class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        sort(nums.begin(),nums.end());
        int count = 1;
        int ans = INT_MIN;
        for(int i =0;i<n-1;i++){
            if(nums[i] == nums[i+1]-1)
                count++;
            else if(nums[i] == nums[i+1]){
                continue;
            }
            else{
                ans = max(ans,count);
                count = 1;
            }
        }
        ans = max(ans,count);
        return ans;
    }
};