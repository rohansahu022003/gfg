class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<int>vis(V,0);
        queue<pair<int,int>>q;
       
        
        vector<vector<int>>adjls(V);
        
        for(auto e: edges){
            int u=e[0];
            int v=e[1];
            adjls[u].emplace_back(v);
            adjls[v].emplace_back(u);
        }
        for( int i=0; i<V; i++){
            if(!vis[i]){
                q.push({i,-1});
                vis[i]=1;
            
        
        while(!q.empty()){
            int currentnode=q.front().first;
            int previousnode=q.front().second;
            q.pop();
            for(auto it : adjls[currentnode]){
                if(!vis[it]){
                q.push({it,currentnode});
                vis[it]=1;
                }
            
                else if(previousnode!=it){
                return true;
            }
            }
        }
            }
            
        }
        return false;
        
    }
};