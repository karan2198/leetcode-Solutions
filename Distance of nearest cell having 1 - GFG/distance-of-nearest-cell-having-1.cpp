//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
     int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m, -1));  // Initialize ans grid with -1

        // Create a queue to perform BFS
        queue<pair<int, int>> q;

        // Add all the cells with 1 to the queue and mark them as visited
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    ans[i][j] = 0;  // Distance to itself is 0
                }
            }
        }

        // Perform BFS
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            // Check adjacent cells
            for (int i = 0; i < 4; i++) {
                int nrow = r + dir[i][0];
                int ncol = c + dir[i][1];

                // Check if the adjacent cell is within bounds and not visited
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && ans[nrow][ncol] == -1) {
                    ans[nrow][ncol] = ans[r][c] + 1;  // Update the distance
                    q.push({nrow, ncol});  // Add the adjacent cell to the queue
                }
            }
        }

        return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends