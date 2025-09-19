
class Solution {
  public:
    int firstNonRepeating(vector<int>& arr) {
      unordered_map<int,pair<int,int>>freq;
      for(int i=0; i<arr.size(); i++){
          if(freq.find(arr[i])==freq.end()){
              freq[arr[i]]={1,i};
          }
          else freq[arr[i]].first++;
      }
      int n=INT_MAX;
      int ans=0;
      for(auto f: freq){
          if(f.second.first==1){
              if(f.second.second<n){
                  n=f.second.second;
                  ans=f.first;
              }
          }
      }
      return ans;
    }
};
