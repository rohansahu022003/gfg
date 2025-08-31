//Position this line where user code will be pasted.
class Solution {
    
    private:
    void dfs(int node, vector<int>& vis, stack<int>& st,vector<vector<int>> &adj){
        vis[node]=1;
        
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it,vis,st,adj);
            }
            
        }
        
        st.push(node);
        
        
    }
    
    void dfsrev(int node, vector<vector<int>>&revadj, vector<int>& vis){
        vis[node]=1;
        
        for(auto it: revadj[node]){
            if(!vis[it]){
                dfsrev(it,revadj,vis);
            }
            
        }
    }
  public:
    int kosaraju(vector<vector<int>> &adj) {
        int n=adj.size();
      vector<vector<int>>revadj(n);
      for(int i=0; i<n; i++){
          for(int j=0; j<adj[i].size(); j++){
              revadj[adj[i][j]].push_back(i);
          }
      }
      
      vector<int>vis(n,0);
      
      stack<int>st;
      
      for(int i=0; i<n; i++){
          if(!vis[i]){
              dfs(i,vis,st,adj);
          }
      }
      
     vector<int>revvis(n,0);
      int count=0;
      while(!st.empty()){
          int s=st.top();
          st.pop();
          if(!revvis[s]){
              count++;
              dfsrev(s,revadj,revvis);
          }
      }
      return count;
        
    }
};