class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int count = 0;
        for(int i = 0 ; i < s.size() ; i++){
            unordered_map<char,bool>mpp;
            for(int j = i ; j < s.size() ;j++){
                if(!mpp[s[j]]){
                    mpp[s[j]] = true;
                }
                else break;
                int length = j - i +1;
                count = max(count , length);
            }
        }
        return count;
    }
};