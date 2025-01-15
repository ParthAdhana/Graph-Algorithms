//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int>ans;
    // Function to return a list containing the DFS traversal of the graph.
    void dfsTraversal(int node, vector<bool>&vis,vector<vector<int>>&adj)
    {
        vis[node]=1;
        ans.push_back(node);
        for(auto next : adj[node])
        {
            if(!vis[next])
            {
                dfsTraversal(next,vis,adj);
            }
        }
    }
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        // Code here
        int n=adj.size();
        vector<bool>vis(n,0);
        ans.clear();
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfsTraversal(i,vis,adj);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.dfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends