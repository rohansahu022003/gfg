class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<pair<int,int>>>adj(n);
        
        for(auto f : flights){
            adj[f[0]].push_back({f[1],f[2]});
        }
        
        using T=pair<int,pair<int,int>>;
        priority_queue<T,vector<T>,greater<T>>pq;
        
        vector<vector<int>>dist(n,vector<int>(K+2,INT_MAX));
        pq.push({0,{src,0}});
        dist[src][0]=0;
        
        while(!pq.empty()){
            auto[cost,p]=pq.top();
            int node=p.first;
            int steps=p.second;
            pq.pop();
            
            if(node==dst)return dist[node][steps];
            if(steps>K)continue;
            
            for(auto it: adj[node]){
                int next=it.first;
                int w=it.second;
                int newcost=w+cost;
                if(newcost<dist[next][steps+1]){
                    pq.push({newcost,{next,steps+1}});
                    dist[next][steps+1]=newcost;
                }
            }
            
        }
        
        return -1;
      
        
    }
};