// User function Template for C++

class Solution {
    private:
    void dfs(int row, int col,vector<vector<int>>& vis,vector<pair<int,int>>& vec,set<vector<pair<int,int>>>& st
    ,vector<vector<int>>& grid, int baserow, int basecol){
        int n=grid.size();
        int m=grid[0].size();
        vis[row][col]=1;
        vec.push_back({row-baserow,col-basecol});
        int drow[]={1,-1,0,0};
        int dcol[]={0,0,1,-1};
        
            for(int i=0; i<4; i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(ncol>=0 && nrow>=0 && ncol<m && nrow<n && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
                    dfs(nrow,ncol,vis,vec,st,grid,baserow,basecol);
                }
            
        }
        
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        set<vector<pair<int,int>>>st;
        
        for(int i=0;i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j]==1){
                    
                    vector<pair<int,int>>vec;
                    dfs(i,j,vis,vec,st,grid,i,j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};
