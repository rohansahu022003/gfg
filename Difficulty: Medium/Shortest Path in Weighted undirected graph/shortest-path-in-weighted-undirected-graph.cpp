class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<int>parent(n+1,0);
        vector<int>distance(n+1,INT_MAX);
        vector<vector<pair<int,int>>>adj(n+1);
        
        
            for(auto e: edges){
                int u=e[0];
                int v=e[1];
                int w=e[2];
                
                adj[u].push_back({v,w});
                adj[v].push_back({u,w});
            }
        
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,1});
        distance[1]=0;
       
        for(int i=0; i<=n; i++)parent[i]=i;
        
        while(!q.empty()){
            int parentnode=q.top().second;
            int dist=q.top().first;
            q.pop();
            
            
            for(auto it: adj[parentnode]){
                int next=it.first;
                int d=it.second;
                int totald=dist+d;
                if(totald<distance[next]){
                     distance[next]=totald;
                    q.push({totald,next});
                    parent[next]=parentnode;
                   
                }
            }
            
            
        }
        
        if(distance[n]==INT_MAX) return {-1};
        
        
        vector<int> path;
        int node = n;
        while(parent[node] != node){
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());

        // Insert distance at the beginning
        path.insert(path.begin(), distance[n]);
        return path;
        
        
        
    }
};