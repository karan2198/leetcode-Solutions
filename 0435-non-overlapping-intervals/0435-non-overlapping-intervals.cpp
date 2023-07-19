class Solution {
public:
     static bool compare(vector<int>&v1,vector<int>&v2){
        return v1[1]<v2[1];
        
    }
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end(),compare);
        int n = arr.size();
        int count = 0;
        for(int i = 0;i <n-1;i++){
            if(arr[i][1]>arr[i+1][0]){
                count++;
                arr[i+1][0] = arr[i][0];
                arr[i+1][1] = arr[i][1];
            }
        }
        return count;
    }
};