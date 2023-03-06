//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    bool dfs(int u,int par,vector<int> adj[],vector<bool> &visited){
        visited[u] = true;
        
        for(auto v:adj[u]){
            if(v==par) continue;
            
            if(visited[v]) return true;
            
            if(dfs(v,u,adj,visited)) return true;
        }
        
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V+1,false);
        for(int i =0;i<V;i++){
            if(!visited[i]){
                bool cycle = dfs(i,-1,adj,visited);
                if(cycle) return true;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends