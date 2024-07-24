class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
       sort(s.begin() , s.end());
        sort(t.begin() , t.end());
        for(int i = 0 ; i < s.length() ; i++){
                if(t[i] != s[i]) return false; 
        }
        return true;
    }
};