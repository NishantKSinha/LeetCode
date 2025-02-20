class Solution {
public:
    int trailingZeroes(int n) {
       /*  //brut force-> integer overflow
        int cnt = 0 ;
        long long fact = 1;
        for(int i =2 ; i <= n ; i++) fact = fact * i;

        while(fact % 10 ==0){
            cnt ++ ;
            fact = fact/10;
        }

        return cnt;*/

        //in this we will basically count the 5 factorial
        int ans =0;

        while(n/5 >0){
            ans += n/5;
            n = n/5;
        }
        return ans;
    }
};