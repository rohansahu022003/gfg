class Solution {
    private:
    bool dfs(vector<vector<int>>& adj,vector<int>& vis,int node, vector<int>& pathvis){
        vis[node]=1;
        pathvis[node]=1;
        
        for(auto it: adj[node]){
            if(!vis[it]){
                if(dfs(adj,vis,it, pathvis))return true;
            }
            else if(pathvis[it])return true;
        }
        pathvis[node]=0;
        return false;
    }
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>>adj(V);
        vector<int>vis(V,0);
        vector<int>pathvis(V,0);
      
        
        for(auto e: edges){
            int u=e[0];
            int v=e[1];
            adj[u].emplace_back(v);
           
        }
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(dfs(adj,vis,i,pathvis))return true;
            }
        }
        return false;
    }
};