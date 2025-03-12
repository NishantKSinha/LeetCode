class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char>uniqueletter;

        for(int i = 0 ; i < s.size();i++){
            uniqueletter.insert(s[i]);
        }
        int result = 0 ;

        for(char ch : uniqueletter){

            int left_idx = -1;
            int right_idx = -1;

            for(int i = 0 ; i < s.size();i++){

                if(s[i] == ch){
                    if(left_idx == -1){
                        left_idx = i;
                    }
                    right_idx = i;
                }
            }

            unordered_set<char>middleunique;
            for(int middle = left_idx+1; middle <= right_idx-1;middle++){
                middleunique.insert(s[middle]);
            }
            result = result + middleunique.size();
        }
        return result;

    }
};