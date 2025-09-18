// User function Template for C++

class Solution {
  public:
    void rotate(vector<int> &arr) {
        vector<int>ans(arr.size());
        
        for(int i=0; i<arr.size(); i++){
            ans[(i+1)%arr.size()]=arr[i];
        }
        arr=ans;
        
    }
};