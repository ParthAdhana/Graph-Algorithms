//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> adj) {
        // code here
        int n=adj.size();
        vector<int>indegree(n,0);
        queue<int>q;
        bool flag=1;
        for(int i=0;i<n;i++)
        {
            for(auto it : adj[i])
                indegree[it]++;
        }
        for(int i=0;i<n;i++)
            if(indegree[i]==0)
                q.push(i);
        if(q.size()==0)return true;
        
        
        int cnt=q.size();
        while(q.size())
        {
            int top=q.front();
            q.pop();
            flag=1;
            for(auto next : adj[top])
            {
                indegree[next]--;
                if(indegree[next]==0)
                {
                    q.push(next);
                    flag=0;
                    cnt++;
                }
            }
        }
        return cnt==n ? false: true;
        
        
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