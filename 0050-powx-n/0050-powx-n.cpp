class Solution {
public:
       double myPow(double x, int n) {
           //recrsion
           //tc == o (logn)
           double ans = 1.0;    
           long nn = n;//we take long nn bcz if we change -2^31 into positive there will be overflow
           if(nn < 0) nn = -1*nn;
           while(nn > 0){
               if(nn%2 != 0){
                   ans = ans *x;
                   nn = nn-1;
               }
               else{
                   x  = x*x;
                   nn = nn/2;
               }
           }
           if(n <  0) return double(1.0)/double(ans);
           return ans;
        
    }
};