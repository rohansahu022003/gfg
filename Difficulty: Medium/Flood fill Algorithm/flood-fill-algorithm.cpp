class Solution {
    private:
    void dfs(int n,int m,vector<vector<int>>& image,int sr, int sc,int drow[],int dcol[],int color,int oldcolor){
       int row=sr;
       int col=sc;
        int nrow,ncol;
        for(int i=0; i<4; i++){
            nrow=row+drow[i];
            ncol=col+dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 &&ncol<m && image[nrow][ncol]==oldcolor){
                image[nrow][ncol]=color;
                dfs(n,m,image,nrow,ncol,drow,dcol,color,oldcolor);
            }
        }
    } 
    
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        int n=image.size();
        int m=image[0].size();
        
        int oldcolor=image[sr][sc];
        if(oldcolor==newColor) return image;
        image[sr][sc]=newColor;
        
        int drow[]={1,-1,0,0};
        int dcol[]={0,0,-1,1};
       
        
        dfs(n,m,image,sr,sc,drow,dcol,newColor,oldcolor);
        return image;
    }
};