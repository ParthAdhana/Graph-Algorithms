//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int node,vector<int>&vis,vector<vector<int>>&adj,vector<int>&dfsVis)
    {
        vis[node]=1;
        dfsVis[node]=1;
        for(auto next : adj[node])
        {
            if(dfsVis[next])return true;
            if(dfs(next,vis,adj,dfsVis))return true;
        }
        dfsVis[node]=0;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> adj) {
        // code here
        int n=adj.size();
        vector<int>vis(n,0);
        vector<int>dfsVis(n,0);
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,vis,adj,dfsVis))return true;
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

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends