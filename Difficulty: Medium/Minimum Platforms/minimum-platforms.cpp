class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        sort(arr.begin(), arr.end());
        sort(dep.begin(),dep.end());
        int n=arr.size();
        int ans=0;
        int trainreached=0;
        int i=0;
        int j=0;
        while(i<n && j<n){
            if(arr[i]<=dep[j]){
                trainreached++;
                i++;
                ans=max(ans,trainreached);
            }
            else{
                trainreached--;
                j++;
            }
            
            
        }
        return ans;
    }
};
