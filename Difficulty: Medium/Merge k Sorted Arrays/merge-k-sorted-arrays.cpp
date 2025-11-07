class Solution {
  public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        priority_queue<int,vector<int>,greater<int>>pq;
        
        vector<int>ans;
        
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[i].size(); j++){
                pq.push(mat[i][j]);
            }
        }
        
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};