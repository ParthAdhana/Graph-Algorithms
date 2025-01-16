//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

//Back-end complete function Template for C++


// } Driver Code Ends
class Solution {
  public:
    const int MAX=1e9;
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        
        // code here
        int n=adj.size();
        vector<int>vis(n,0);
        vector<int>ans(n,MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;// dist,node
        pq.push({0,src});
        while(pq.size())
        {
            int dist=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            ans[node]=dist;
            if(vis[node])continue;
            vis[node]=1;
            for(auto next : adj[node])
            {
                if(!vis[next])
                {
                   if(ans[next]>dist+1)//change for weighted graph
                   {
                        ans[next]=dist+1;
                        pq.push({dist+1,next});
                   }
                }
            }
        }
        for(int i=0;i<n;i++)
            if(ans[i]==MAX)ans[i]=-1;
            
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