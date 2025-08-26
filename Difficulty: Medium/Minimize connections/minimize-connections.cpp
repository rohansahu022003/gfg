class disjointsets{
vector<int>parent,size;
public:

disjointsets(int n){
    parent.resize(n);
    size.resize(n+1,1);
    for (int i=0; i<n;i++){
        parent[i]=i;
    }
}

int ulpa(int node){
    if(node==parent[node])return node;

    return parent[node]=ulpa(parent[node]);
}
void unionbysize(int u, int v){
    int up_u=ulpa(u);
    int up_v=ulpa(v);
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
int components(int& count,int n){
     for(int i=0; i<n; i++){
            if(i==parent[i])count++;

        }
        return count;
}

};

class Solution {
  public:
    int minimumConnections(int n, vector<vector<int>> &connections) {
         int v=connections.size();
        if(v<n-1)return -1;
        disjointsets ds(n);

        for(auto it:connections){
            int x=it[0];
            int y=it[1];
            ds.unionbysize(x,y);   
        }
        int component=0;
       
        ds.components(component,n);
        return component-1;
        
    }
};