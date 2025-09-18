class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        unordered_map<int,int>frq;
        for(int i=1; i<=arr.size(); i++){
            frq[i]=0;
        }
        
        for(auto a: arr){
            frq[a]++;
        }
        
        vector<int>ans;
        
        for(auto f: frq){
            if(f.second==2)ans.push_back(f.first);
            
        }
        for(auto f: frq){
            if(f.second==0)ans.push_back(f.first);
        }
        
        return ans;
    }
};