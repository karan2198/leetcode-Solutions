class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count = 0;
        long long ans = 0;
        
        for(int i = 0;i<nums.size();i++){
           if(nums[i] == 0)
           {
               count++;
           }
           else
           {
                ans+=(count*(count+1))/2;
               cout<<ans<<" ";
                count = 0;
           }
        }
        
        ans+=(count*(count+1))/2;
        
        return ans;
    }
};