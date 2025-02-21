class Solution {
public:
    int countAtMostK(string& s , int k)
    {
        if(k == 0) return 0;
        map<char , int> mpp ;
        int left = 0 , right = 0 , cnt = 0 , dist = 0;
        
        while(right < s.length()){
            
            if(mpp[s[right]] == 0) dist++;
            mpp[s[right]]++;
            
            while(dist> k)
            {
                mpp[s[left]]--;
                if(mpp[s[left]] == 0)dist--;
                left++;
            }
            
            cnt += (right - left + 1);
            right++;
        }
        
        return cnt;
        
    }
    int numberOfSubstrings(string s) {
        int k = 3;
        return countAtMostK(s , k) - countAtMostK(s , k - 1);
    }
};