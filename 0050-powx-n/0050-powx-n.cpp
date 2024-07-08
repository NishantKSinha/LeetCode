class Solution {
    private:
        double Pow(double x, int n) {
         if(n == 0){
            return 1 ;
        }
        return x * Pow(x , n-1);
    }
public:
        double myPow(double x, int n) {
        if (n == INT_MAX) return (x == 1) ? 1 : (x == -1) ? -1 : 0;
        if (n == INT_MIN) return (x == 1 || x == -1) ? 1 : 0;
            double num = 1 ; 
            if(n >= 0){
                num = Pow(x , n);
            }
            else{
                n = -n;
                num = Pow(x , n);
                num = 1.0/num;
            }
            return num ;
        
        
    }
};