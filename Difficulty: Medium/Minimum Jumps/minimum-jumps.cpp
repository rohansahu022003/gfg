class Solution {
  public:
    int minJumps(vector<int>& arr) {
       int i=0,jump=0,farthest=0,end=0;
       if(arr[0]==0)return -1;
       if(arr.size()<=1)return 0;
       
       for(int i=0; i<arr.size()-1; i++){
           farthest=max(farthest,i+arr[i]);
           
           if(i==end){
               jump++;
               end=farthest;
               if(end>=arr.size()-1)return jump;
           }
       }
       return -1;
    }
};
