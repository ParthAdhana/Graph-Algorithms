class Solution {
public:
    bool dfs(int node, vector<int>&vis,vector<vector<int>>&graph,int parity)
    {
        vis[node]=parity;
        for(auto next : graph[node])
        {
            if(vis[next]==-1)
            {
                if(!dfs(next,vis,graph,parity^1))return false;
            }
            if(vis[next]==vis[node])return false;
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,-1);
        for(int i=0;i<n;i++)
        {
            if(vis[i]!=-1)continue;
            if(!dfs(i,vis,graph,0))return false;
        }
        return true;
    }
};