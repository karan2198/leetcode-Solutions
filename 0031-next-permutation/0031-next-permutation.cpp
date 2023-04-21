class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-2;
        while(i>=0){
            if(nums[i]>=nums[i+1]){
                i--;
            }
            else{
                break;
            }
        }
        if(i<0){
            sort(nums.begin(),nums.end());
        }
        else{
            int mini = INT_MAX ;
            int index = 0;
            for(int j = i;j<n;j++){
                if(nums[j]>nums[i]){
                    if(nums[j]<mini)
                    {   
                        mini = nums[j];
                        index = j;
                    }
                }
            }
           swap(nums[i],nums[index]);
            sort(nums.begin()+i+1,nums.end());
        }
    }
};