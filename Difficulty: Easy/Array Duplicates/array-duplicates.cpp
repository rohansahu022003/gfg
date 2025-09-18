class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        unordered_map<int,int>freq;
        
        for(int i=0; i<arr.size(); i++){
            freq[arr[i]]++;
        }
        
        vector<int>ans;
        
        for(auto m:freq){
            if(m.second==2)ans.push_back(m.first);
        }
        return ans;
    }
};