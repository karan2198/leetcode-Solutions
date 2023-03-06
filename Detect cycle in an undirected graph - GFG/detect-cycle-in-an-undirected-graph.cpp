//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
   bool isCyclicConntected( int s,vector<int> adj[], int V, vector<bool>& visited) {
    // Set parent vertex for every vertex as -1.
    vector<int> parent(V, -1);
 
    queue<int> q;

    visited[s] = true;
    q.push(s);
 
    while(!q.empty()) {
        int u = q.front();
        q.pop();
             
        for(auto v : adj[u]) {
            if(!visited[v]) {
                visited[v] = true;
                q.push(v);
                parent[v] = u;
            }
            else if(parent[u] != v)
                return true;
        }
    }
    return false;
}
 
bool isCyclicDisconntected(int V,vector<int> adj[]) {
    
    // Mark all the vertices as not visited
    vector<bool> visited(V, false);
 
    for(int i = 0; i < V; i++)
        if(!visited[i] && isCyclicConntected(i,adj, V, visited))
            return true;
    return false;
}
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
       if (isCyclicDisconntected( V,adj))
        return true;
    else
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