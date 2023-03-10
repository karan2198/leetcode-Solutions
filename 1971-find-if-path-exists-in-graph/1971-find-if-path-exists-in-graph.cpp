class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>> map;
        for(auto x: edges){
            vector<int>temp = x;
            
            int u = temp[0];
            int v = temp[1];
            
            map[u].push_back(v);
            map[v].push_back(u);
        }
        
        vector<bool>visited(n+1,false);
        
        queue<int>q;
        q.push(source);
        visited[source] = true;
        
        while(!q.empty()){
            int v = q.front();
            q.pop();
            
            vector<int>temp = map[v];
            for(int i=0; i<temp.size(); i++){
               int vertex = temp[i];
                if(visited[vertex] == false){
                    q.push(vertex);
                    visited[vertex] = true;
                }
            }
        }
        
        return visited[destination];
    }
};