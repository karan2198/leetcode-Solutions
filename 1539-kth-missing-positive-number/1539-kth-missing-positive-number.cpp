class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
         vector<int> v(1e4+1,-1);
        for(int i =0;i<arr.size();i++)
        {
            v[arr[i]]=0;
        }
        int temp =0;
        int ans ;
        
        for(int i =1;i<v.size();i++)
        {
            if(v[i]!=0)
            {
            temp++;
           // cout<<temp<<" ";
            }
            if(temp==k){
                ans = i;
                break;
            }
        }
         return ans;
    }
};