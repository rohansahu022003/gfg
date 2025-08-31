class Solution {
    int timer=1;
    private:
    void dfs(int node, int parent, vector<vector<int>>& adj,
    vector<int>& vis, vector<int>&tin, vector<int>& low,map<int,int>&mark){
        vis[node]=1;
        tin[node]=low[node]=timer;
        timer++;
        
        int child=0;
        
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it,node, adj, vis, tin,low,mark);
                low[node]=min(low[node],low[it]);
                
                if(low[it]>=tin[node] && parent!=-1){
                    mark[node]=1;
                }
                child++;
            }
            else{
                low[node]=min(low[node],tin[it]);
            }
        }
        if(child>1 && parent==-1){
            mark[node]=1;
        }
        
    }
  public:
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        vector<vector<int>>adj(V);
        
        for(auto e:edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            }
            
            vector<int>vis(V,0);
            vector<int>tin(V);
            vector<int>low(V);
            map<int,int>mark;
            for(int i=0; i<V; i++){
                if(!vis[i]){
                dfs(i,-1,adj,vis,tin,low,mark);
            }
            }
            
            vector<int>ans;
            
            for(auto m: mark){
                if(m.second==1){
                    ans.push_back(m.first);
                }
            }
            
            if(ans.size()==0)return {-1};
            return ans;
    }
};