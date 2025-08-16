class Solution {

private:
void dfs( vector<vector<int>>& vis,vector<vector<char>>& grid, int n, int m,int row,int col ){
    vis[row][col]=1;
    int drow[]={1,-1,0,0,1,-1,-1,1};
    int dcol[]={0,0,1,-1,1,-1,1,-1};
    
    for(int i=0; i<8; i++){
        int nrow=row+drow[i];
        int ncol=col+dcol[i];
        if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid[nrow][ncol]=='L' && !vis[nrow][ncol]){
            vis[nrow][ncol]=1;
            dfs(vis,grid,n,m,nrow,ncol);
        }
    }
}
  public:
    int countIslands(vector<vector<char>>& grid) {
        
    int n=grid.size();
    int m=grid[0].size();
    
    vector<vector<int>>vis(n, vector<int>(m,0));
    int count=0;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            
            if(grid[i][j]=='L' && !vis[i][j]){
                count++;
                dfs(vis,grid,n,m, i,j);
            }
        }
    }
    return count;
    }
};