class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
      unordered_map<int,int>frq;
      
      for(int i=0; i<a.size();i++){
          frq[a[i]]++;
      }
      for(int i=0; i<b.size(); i++){
          frq[b[i]]++;
      }
      
      vector<int>ans;
      
      for(auto f: frq){
          ans.push_back(f.first);
      }
      return ans;
    }
};