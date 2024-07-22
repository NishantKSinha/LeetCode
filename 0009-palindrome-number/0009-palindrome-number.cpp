class Solution {
public:
    bool isPalindrome(int x) {
        long long number=x;
        if(x==0){
            return true;
        }

        if(x<0){
            return false;
        }
        int temp=x;
        long long ans =0;
        while(x!=0){
            int digit=x%10;
            ans=(ans*10)+digit;
            x=x/10;

        }
         
        if(temp==ans)
       {
            return true;
        }
        else{
            return false;
        }
        
    }
};