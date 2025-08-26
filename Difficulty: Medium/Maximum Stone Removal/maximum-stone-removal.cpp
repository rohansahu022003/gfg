class disjointsets{
    vector<int>parent,size;
public:    
    disjointsets(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0; i<n;i++){
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
    int maxRemove(vector<vector<int>>& stones, int n) {
        int maxrow=0,maxcol=0;
        
        for(auto s:stones){
            maxrow=max(maxrow,s[0]);
            maxcol=max(maxcol,s[1]);
        }
        int offset=maxrow+1;
        disjointsets ds(maxrow+maxcol+2);
        
        set<int>nodes;
        for(auto s:stones){
            int row=s[0];
            int col=s[1]+offset;
            ds.unionbysize(row,col);
            nodes.insert(row);
            nodes.insert(col);
        }
        int c=0;
        for(auto node: nodes){
            if(ds.fup(node)==node)c++;
        }
        return n-c;
    }
};