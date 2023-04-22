//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        // Code here
          map<long long,long long> mp; // frequency of every element
    unordered_map<long long,long long> Presum; // Prefix sum till every element
    for(int i=0;i<n;i++)
    {
        mp[arr[i]]++;
    }
    long long prevsum=0;
    for(auto it:mp)
    {
        Presum[it.first]=prevsum;
        prevsum+=it.second*it.first; 
    }
    vector<long long> ans;
    for(int i=0;i<n;i++)
    {
        long long currans=Presum[arr[i]];
        ans.push_back(currans);
    }
    return ans;

    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob; 
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends