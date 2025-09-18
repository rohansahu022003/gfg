class Solution {
  public:
    void segregateElements(vector<int>& arr) {
       vector<int>p;
       vector<int>n;
       
       for(int i=0; i<arr.size(); i++){
           if(arr[i]<0)n.push_back(arr[i]);
           else p.push_back(arr[i]);
       }
       
       int i=0,j=0,k=0;
       
       while(i<arr.size()&& j<p.size())arr[i++]=p[j++];
       while(i<arr.size() && k<n.size())arr[i++]=n[k++];
    }
};