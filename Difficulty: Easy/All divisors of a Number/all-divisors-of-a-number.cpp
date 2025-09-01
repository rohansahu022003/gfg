class Solution {
  public:
    void print_divisors(int n) {
        int root=sqrt(n);
        vector<int>divisor;
        
        for(int i=1; i<=root; i++){
            if(n%i==0){
                divisor.push_back(i);
                if(i!=n/i){
                divisor.push_back(n/i);
                }
            }
        }
        sort(divisor.begin(), divisor.end());
        
        for(int i=0; i<divisor.size(); i++){
            cout<<divisor[i]<<" ";
        }
    }
};