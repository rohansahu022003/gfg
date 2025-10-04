class Solution {
  public:
    int maxWater(vector<int> &height) {
      int i=0;
        int j=height.size()-1;
        int maxarea=0;
        while(i<j){
            int b=min(height[i],height[j]);
            int l=j-i;
            ;maxarea=max(maxarea,b*l);
            if(height[i]<height[j])i++;
            else j--;

          

        }
        return maxarea;
    }
};