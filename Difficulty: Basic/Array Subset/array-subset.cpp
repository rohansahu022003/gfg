class Solution {
  public:
    // Function to check if b is a subset of a
    bool isSubset(vector<int> &a, vector<int> &b) {
        unordered_map<int,int>mpp1;
        unordered_map<int,int>mpp2;
        
        int n=a.size(),m=b.size();
        
        for(int i=0; i<n; i++){
            mpp1[a[i]]++;
        }
        for(int i=0; i<m; i++){
            mpp2[b[i]]++;
        }
        
        for(auto m: mpp2){
            if(mpp1[m.first]<m.second)return false;
        }
        return true;
        
    }
};