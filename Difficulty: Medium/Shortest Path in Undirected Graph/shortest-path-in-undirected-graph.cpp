class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int n=adj.size();
        
        vector<int>vis(n,0);
        vector<int>shortest(n,0);
        queue<pair<int,int>>q;
        int steps=0;
        q.push({src,steps});
        
        vis[src]=1;
        
        while(!q.empty()){
            int node=q.front().first;
            steps=q.front().second;
            shortest[node]=steps;
            q.pop();
            for(auto it : adj[node]){
                if(!vis[it]){
                    q.push({it,steps+1});
                    vis[it]=1;
                    
                }
            }
        }
        for(int i=0; i<n; i++){
            if(shortest[i]==0 && i!=src){
                shortest[i]=-1;
            }
        }
        return shortest;
    }
};