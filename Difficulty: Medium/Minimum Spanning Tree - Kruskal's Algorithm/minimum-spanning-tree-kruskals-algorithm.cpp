class disjointsets{
    vector<int>parent, size;
    public:
    disjointsets(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0; i<=n; i++){
            parent[i]=i;
        }
    }
    int fup(int node){
        if(node==parent[node])
        {return node;}
        
      return  parent[node]=fup(parent[node]);
    }
    
    void unionbysize(int u, int v){
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
    int kruskalsMST(int V, vector<vector<int>> &edges) {
      
      sort(edges.begin(),edges.end(),[](const vector<int>& a, const vector<int>& b){
          return a[2]<b[2];
      });
      int sum=0;
      disjointsets ds(V);
      
      for(auto it :edges){
          int u=it[0];
          int v=it[1];
          int w=it[2];
          
          if(ds.fup(u)!=ds.fup(v)){
              sum+=w;
              ds.unionbysize(u,v);
          }
          
      }
        return sum;
    }
};