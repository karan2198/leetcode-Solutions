//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool cycle(int V,int i,vector<int> adj[],vector<int> &visited,vector<int> &currvisited){
        visited[i] = true;
        currvisited[i] = true;
        
        for(auto x:adj[i]){
            if(!visited[x]){
                if(cycle(V,x,adj,visited,currvisited))
                   return true;
            }
            else if(visited[x] == true && currvisited[x] == true)
                     return true;
        }
        
        currvisited[i] = false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> visited(V+1,false);
        vector<int> currvisited(V+1,false);
        
        for(int i =0;i<V;i++){
            if(!visited[i]){
                if(cycle(V,i,adj,visited,currvisited))
                 return true;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends