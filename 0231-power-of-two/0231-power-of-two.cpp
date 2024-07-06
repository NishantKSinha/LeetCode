class Solution {
public:
    bool isPowerOfTwo(int n) {
        //also done by power method pow(2 , i) and i < 31 && i = 0
        int cnt = 0;
            while(n != 0 && n > 0) {
                n &= (n-1);
                cnt++;
            }
            if(cnt == 1){
                return true;
            }
            return false;

    }
};