class Solution {
public:
    bool bfs(int node, vector<int>&vis,vector<vector<int>>&graph,int parity)
    {
        queue<int>q;
        q.push(node);
        vis[node]=1;
        while(q.size())
        {
            int top=q.front();
            q.pop();
            for(auto next : graph[top])
            {
                if(vis[next]==vis[top])return false;
                if(vis[next]==-1)
                {
                    vis[next]=vis[top]^1;
                    q.push(next);
                }
            }
        }
        return true;
        
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,-1);
        for(int i=0;i<n;i++)
        {
            if(vis[i]!=-1)continue;
            if(!bfs(i,vis,graph,0))return false;
        }
        return true;
    }
};