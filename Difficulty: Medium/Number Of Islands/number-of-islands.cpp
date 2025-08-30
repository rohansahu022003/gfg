class disjointsets{
  vector<int>parent,size;
  public:
  disjointsets(int n){
      parent.resize(n+1);
      size.resize(n+1,1);
      for(int i=0 ; i<=n; i++){
          parent[i]=i;
      }
  }
  
  int fup(int node){
      if(node==parent[node])return node;
      return parent[node]=fup(parent[node]);
  }
  
  void unionbysize(int u,int v){
      int up_u=fup(u);
      int up_v=fup(v);
      if(up_u==up_v)return;
      else if(size[up_u]>size[up_v]){
          parent[up_v]=up_u;
          size[up_u]+=size[up_v];
      }
      else{
          parent[up_u]=up_v;
          size[up_v]+=size[up_u];
      }
  }
};
class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        disjointsets ds(n*m);
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<int>ans;
        int cnt=0;
        
        for(auto it:operators){
            int row=it[0];
            int col=it[1];
            if(vis[row][col]==1){
                ans.push_back(cnt);
                continue;
            }
            vis[row][col]=1;
            cnt++;
            int drow[]={1,-1,0,0};
            int dcol[]={0,0,-1,1};
            for(int i=0; i<4; i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    if(vis[nrow][ncol]==1){
                        int node=row*m+col;
                        int nextnode=nrow*m+ncol;
                        if(ds.fup(node)!=ds.fup(nextnode)){
                            cnt--;
                            ds.unionbysize(node,nextnode);
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        
        return ans;
        
    }
};
