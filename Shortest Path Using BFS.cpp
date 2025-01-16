//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

//Back-end complete function Template for C++


// } Driver Code Ends
class Solution {
  public:
    
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        int n=adj.size();
        vector<int>ans(n,-1);
        vector<int>vis(n,0);
        queue<pair<int,int>>q;//(node,dist)
        ans[src]=0;
        q.push({src,0});
        vis[src]=1;
        while(q.size())
        {
            int node=q.front().first;
            int dist=q.front().second;
            q.pop();
            for(auto next : adj[node])
            {
                if(!vis[next])
                {
                    vis[next]=1;
                    q.push({next,dist+1});
                    ans[next]=dist+1;
                }
            }
        }
        return ans;

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
            adj[v].push_back(u);
        }

        int src;
        cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(adj, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
        cout << "~\n";
    }
}

// } Driver Code Ends