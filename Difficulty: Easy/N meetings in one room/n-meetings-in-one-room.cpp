class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n=start.size();
        
        vector<pair<int,int>>p;
        
        for(int i=0; i<n; i++){
            p.push_back({end[i],start[i]});
        }
        
       sort(p.begin(),p.end());
       int lastend=-1;
       int ans=0;
        for(auto m:p){
           if(m.second>lastend){
               ans++;
               lastend=m.first;
           }
        }
        return ans;
    }
};