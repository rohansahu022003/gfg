class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
       int j=0,i=0,sum=0,n=arr.size();
       while(j<n){
           sum+=arr[j];
           
           while(sum>target && i<=j){
               sum-=arr[i];
               i++;
           }
           if(sum==target)return {i+1,j+1};
           
           j++;
       }
        
        return {-1};
    }
};