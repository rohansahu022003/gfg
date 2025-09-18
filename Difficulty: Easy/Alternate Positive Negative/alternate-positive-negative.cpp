// User function template for C++
class Solution {
  public:
    void rearrange(vector<int> &arr) {
        vector<int>positive;
        vector<int>negative;
        
        for(int i=0; i<arr.size(); i++){
            if(arr[i]<0)negative.push_back(arr[i]);
            else positive.push_back(arr[i]);
    }
    int j=0,k=0,i=0;
    while(i<arr.size() && j<positive.size() && k<negative.size()){
        if(i%2==0){
            arr[i]=positive[j++];
        }
        else{
            arr[i]=negative[k++];
        }
        i++;
    }
    while(i<arr.size() && j<positive.size())arr[i++]=positive[j++];
    while(i<arr.size() && k<negative.size())arr[i++]=negative[k++];
    }
};