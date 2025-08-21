// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        
        int mod=1e5;
        vector<int>dist(1e5,INT_MAX);
        dist[start]=0;
        if(end==start)return 0;
        queue<pair<int,int>>q;
        
        q.push({start,0});
        
        while(!q.empty()){
            int node=q.front().first;
            int step=q.front().second;
            q.pop();
           
            for(auto it : arr){
                int next=(node*it)%mod;
               
                 
                if(step+1<dist[next]){
                     q.push({next,step+1});
                     dist[next]=step+1;
                     if(next==end)return dist[next];
                }
            }
        }
        return -1;
    }
};
