class Solution {
  public:
    bool isPrime(int n) {
        int root=sqrt(n);
        if(n==1)return false;
        for(int i=2 ;i<=root; i++){
            if(n%i==0)return false;
        }
        return true;
    }
};
