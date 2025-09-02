class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        unordered_map<int,int>freq;
        long n=arr.size()/2;
        
        for(int i=0; i<arr.size(); i++){
            freq[arr[i]]++;
        }
       
        for(auto f:freq){
            if(f.second>n){
                return f.first;
            }
        }
        return -1;
    }
};