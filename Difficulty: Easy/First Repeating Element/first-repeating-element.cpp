class Solution {
  public:
    int firstRepeated(vector<int> &arr) {
        unordered_map<int,int>occurance;
        int ind=INT_MAX;
        for(int i=0; i<arr.size(); i++){
            if(occurance.find(arr[i])!=occurance.end()){
                ind=min(ind,occurance[arr[i]]);
            }
            else{
            occurance[arr[i]]=i;
        }
        }
       
        if(ind==INT_MAX)return -1;
        return ind+1;
      
    }
};