class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        sort(a.begin(),a.end(),greater<int>());
        sort(b.begin(), b.end(),greater<int>());
        priority_queue<pair<int,pair<int,int>>>pq;
        int n=a.size();
        int m=b.size();
        set<pair<int,int>>used;
        vector<int>ans;
        int i=0;
        int j=0;
        pq.push({a[0]+b[0],{0,0}});
        
        used.insert({0,0});
        while(k-- && !pq.empty()){
            auto it=pq.top();
            int sum=it.first;
            i=it.second.first;
            j=it.second.second;
            pq.pop();
            ans.push_back(sum);
            if(i+1<n && !used.count({i+1,j})){
                pq.push({a[i+1]+b[j],{i+1,j}});
                used.insert({i+1,j});
                
            }
            if(j+1<m && !used.count({i,j+1})){
                pq.push({a[i]+b[j+1],{i,j+1}});
                used.insert({i,j+1});
            }
    
        }
       
        
        return ans;
        
        
        
    }
};
        