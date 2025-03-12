class Solution {
public:
    string reverseWords(string s) {
        //approach1 == by loop

        int n = s.length();
        int i = 0 ;
        while(i < n){

            if(s[i] != ' '){
                int j = i ;

                while(j < n && s[j] != ' '){
                    j++;
                }
                reverse(s.begin() + i, s.begin()+j); //reverse krdega j ke ek piche the
                i = j ;
                i++;
            }
        }
        return s;
    }
};