class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int arr[9][2] = {{1,-2},{1,2},{2,-1},{2,1},{-1,2},{-1,-2},{-2,1},{-2,-1}};
        int x = 0 , y = 0 , ans = 0;
        if(grid[0][0]!=0) return false;
        while(true){
            int count = 0;
            for(int ind = 0;ind<8;ind++){
             int i = x + arr[ind][0];
             int j = y + arr[ind][1];
             
             if(i<n && i>=0 && j<n && j>=0){
                   if(grid[i][j] == ans + 1){
                      x = i;
                      y = j;
                      count = 1;
                       ans++;
                       break;
                       
                   }
              }
            }
            if(count == 0 || ans == n*n - 1)
                break;
        }
        
        if(ans == n*n - 1) return true;
        return false;
    }
};