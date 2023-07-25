class Solution {
public:
    int solve(vector<int>& arr, int s, int l){
        int mid = s + (l-s)/2;
        if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) return mid;
        else{
            if(arr[mid] < arr[mid-1]){
                l = mid;
               return solve(arr,s,l);
            }
            else if(arr[mid] < arr[mid+1]){
                s = mid;
                return solve(arr,s,l);
            }
        }
        return -1;
    }
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        return solve(arr,0,n-1);
    }
};