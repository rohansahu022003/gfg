class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>adj(V);
        
        for(auto e: edges){
            int u=e[0];
            int v=e[1];
            int w=e[2];
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        using T=pair<int,pair<int,int>>;
        priority_queue<T,vector<T>,greater<T>>pq;
        vector<int>vis(V,0);
        vector<pair<int,int>>mst;
        int totalsum=0;
        pq.push({0,{0,-1}});
        
        while(!pq.empty()){
            auto it= pq.top();
            int w=it.first;
            int node=it.second.first;
            int parent=it.second.second;
            pq.pop();
            
            if(!vis[node]){
            totalsum=totalsum+w;
            if(parent!=-1)mst.push_back({parent,node});
            }
            vis[node]=1;
            
            for(auto nei : adj[node]){
                int next=nei.first;
                int wnew=nei.second;
                if(!vis[next]){
                    pq.push({wnew,{next,node}});
                }
            }
        }
        return totalsum;
        
    }
};