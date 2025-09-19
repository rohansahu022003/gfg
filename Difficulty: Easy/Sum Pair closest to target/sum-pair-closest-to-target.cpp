class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
      int closest=INT_MAX;
      int diff=INT_MIN;
      int a,b;
      if(arr.size()==1)return {};
      sort(arr.begin(),arr.end());
      int i=0, j=arr.size()-1;
      while(i<j){
          int sum=arr[i]+arr[j];
          int d=abs(arr[i]-arr[j]);
          if(abs(target-sum)<closest){
              a=arr[i];
              b=arr[j];
              closest=abs(target-sum);
              diff=d;
          }
          else if(abs(target-sum)==closest){
              if(d>diff){
                  a=arr[i];
                  b=arr[j];
              }
          }
          
          if(target-sum<0)j--;
          else i++;
      }
      if(a>b)return {b,a};
      return {a,b};
        
    }
};