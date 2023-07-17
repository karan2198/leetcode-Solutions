//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		   unordered_map<char, int> freq;
    queue<char> nonRepeating;

    string result;

    for (char c : A) {
        // Increment the frequency count of the character
        freq[c]++;
        // If it's the first time encountering the character, add it to the queue
        if (freq[c] == 1) {
            nonRepeating.push(c);
        }

        // Check if the front of the queue is still the first non-repeating character
        while (!nonRepeating.empty() && freq[nonRepeating.front()] > 1) {
            nonRepeating.pop();
        }

        // Build the result string based on the front of the queue
        if (!nonRepeating.empty()) {
            result += nonRepeating.front();
        } else {
            result += '#';
        }
    }

    return result;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends