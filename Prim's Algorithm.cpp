//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
    
        int n=V;
        int ans=0;
        int sz=0;
        vector<bool>mst(n,0);
        vector<int>dis(n,1e7);
        mst[0]=1;
        dis[0]=0;
        sz=1;
        int node=0;
        while(sz!=V)
        {
            for(auto next: adj[node])
            {
                int node=next[0];
                int wt=next[1];
                if(mst[node]==0)
                {
                    dis[node]=min(dis[node],wt);
                }
            }
            int min_dis=1e9;
            for(int i=0;i<n;i++)
            {
                if(mst[i]==0)
                {
                    if(min_dis>dis[i])
                    {
                        node=i;
                        min_dis=dis[i];
                    }
                }
            }
            sz++;
            ans+=min_dis;
            mst[node]=1;
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
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends