//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumSum(string s) {
        // code here
         int n = s.length();
    int left = 0;
    int right = n - 1;

    // Checking for validity
    while (left <= right) {
        if (s[left] != s[right] && s[left] != '?' && s[right] != '?')
            return -1;
        
        left++;
        right--;
    }

    left = 0;
    right = n - 1;
    std::string str;

    // Forming left half of new string while skipping indexes where both chars at
    // left and right index are '?' as they won't make a difference in the final output
    while (left <= right) {
        if (s[left] != '?')
            str += s[left];
        else if (s[right] != '?')
            str += s[right];

        left++;
        right--;
    }

    int res = 0;
    for (int i = 1; i < str.length(); i++) {
        res += 2*std::abs(str[i] - str[i - 1]);
    }

    return res;
    
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        int ans = ob.minimumSum(s);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends