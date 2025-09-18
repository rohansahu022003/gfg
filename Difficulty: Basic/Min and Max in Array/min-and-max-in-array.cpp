// User function Template for C++
class Solution {
  public:
    pair<int, int> getMinMax(vector<int> arr) {
        pair<int,int>ans(INT_MAX,INT_MIN);
        
        
        for(int i=0; i<arr.size(); i++){
            ans.first=min(ans.first,arr[i]);
            ans.second=max(ans.second,arr[i]);
        }
        
        return ans;
    }
};