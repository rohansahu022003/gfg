// User function Template for C++
class Solution {
    private:
    int power(int n){
        int original=n;
        for(int i=0; i<2; i++){
            n*=original;
        }
        return n;
    }
  public:
    bool armstrongNumber(int n) {
        int sum=0;
        int check=n;
        while(n){
            int d=n%10;
            n/=10;
            
            sum+=power(d);
        }
    
        
        if(sum==check)return true;
        return false;
    }
        
};