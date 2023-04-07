class Solution {
public:
     bool bfs(int x, int y, int m, int n, vector<vector<int>>& grid, vector<vector<bool>>& visit,int &count){
        queue<pair<int,int>> q;
        q.push({x,y});
        visit[x][y] = true;
        bool isClosed = true;
        
        vector<int> dirx{0, 1, 0, -1};
        vector<int> diry{-1, 0, 1, 0};
        
        while(!q.empty()){
            x = q.front().first;   
            y = q.front().second;  
            q.pop();
            
            for(int i = 0;i<4;i++){
                int r = x + dirx[i];
                int c = y + diry[i];
                
                if (r < 0 || r >= m || c < 0 || c >= n){
                    isClosed = false;
                }
                else if(grid[r][c] == 1 && !visit[r][c]){
                    q.push({r,c});
                    visit[r][c] = true;
                    count++;
                }
            }
        }
        return isClosed;
    }
    int numEnclaves(vector<vector<int>>& grid) {
         int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visit(m,vector<bool>(n));
        int ans = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                int count = 1;
                if(grid[i][j] == 1 && !visit[i][j] && bfs(i,j,m,n,grid,visit,count))
                    ans+=count;
            }
        }
        return ans;
    }
};