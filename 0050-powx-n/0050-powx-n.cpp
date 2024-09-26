class Solution {
public:
    double solve(double x , long n){
        double ans ;
        if(n == 0) ans = 1;
        if(n < 0) ans = pow(1/x , -n);
        if(n > 0) ans = pow(x,n);
        return ans;
    }
       double myPow(double x, int n) {
               
           return solve(x,(long)n);
        
    }
};