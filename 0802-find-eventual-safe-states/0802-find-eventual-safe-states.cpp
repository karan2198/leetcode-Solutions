class Solution {
public:
    
    bool cycle(int s,vector<vector<int>>& graph,vector<int> &visited,vector<int> &currvisited,vector<int> &ans){
        visited[s] = true;
        currvisited[s] = true;
        
        for(auto x: graph[s]){
               if(!visited[x]){
                  if(cycle(x,graph,visited,currvisited,ans))
                  {
                       ans[s] = true;
                      return true;
                  }
               }
            else if(visited[x] && currvisited[x])
            {
                   ans[s] = true;
                return true;
            }
                
        }
        
        currvisited[s] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> visited(V+1,false);
        vector<int> currvisited(V+1,false);
        vector<int> ans(V+1,false);
        vector<int> safenode;
        for(int i = 0; i<V; i++){
           if(!visited[i]){
              if(cycle(i,graph,visited,currvisited,ans))
                  ans[i] = true;
           }
            
        }
        for(int i = 0; i<V;i++){
            if(!ans[i])
                safenode.push_back(i);
        }
        
        sort(safenode.begin(),safenode.end());
        
        return safenode;
    }
};