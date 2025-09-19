// User function template for C++

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
       map<int,int>element;
       
       for(int i=0; i<arr.size(); i++){
           element[arr[i]]++;
       }
       int ans;
       for(auto m: element){
           if(k<=m.second)return m.first;
           
           k-=m.second;
       }
       return ans;
    }
};