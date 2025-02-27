class Solution {
public:
    bool isvowel(char &ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
           ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' ) return true;

           return false;
    }
    bool halvesAreAlike(string s) {
        int n = s.size();
        int mid = s.size()/2;
        int i =0 , j = mid ;
        int cnt1 = 0 , cnt2 = 0;
        while(i < mid && j < n){
            if(isvowel(s[i])) cnt1++;

            if(isvowel(s[j])) cnt2++;

            i++;
            j++; 
        }

        return cnt1 == cnt2;
    }
};