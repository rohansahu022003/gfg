// User function Template for C++

class Solution {
    int timer=1;
    private:
    void dfs(int node, int parent, vector<int>& vis, vector<int>& tin, vector<int>& low, map<int,int>&mark,
    vector<int> adj[]){
        vis[node]=1;
        
        tin[node]=low[node]=timer;
        timer++;
        int child=0;
        
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it,node, vis, tin,low,mark,adj);
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
    vector<int> articulationPoints(int V, vector<int> adj[]) {
       vector<int>vis(V,0);
       vector<int>tin(V);
       vector<int>low(V);
       map<int,int>mark;
       
       dfs(0,-1,vis,tin,low,mark,adj);
       
       vector<int>ans;
       
       for(auto m:mark){
           if(m.second==1){
               ans.push_back(m.first);
           }
       }
       
       if(ans.size()==0)return {-1};
       return ans;
        
    }
};