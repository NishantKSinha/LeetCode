class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0 ;
        int r = 0 ;
        int cnt = 0;
        int minlen = 1e9;
        int startindex = -1;
        unordered_map<char,int>mpp;
        for(int i = 0 ; i < t.size() ; i++){
            mpp[t[i]]++;
        }
        
        while(r < s.size()){
            if(mpp[s[r]] > 0){
                cnt = cnt+1;
                mpp[s[r]]--;
            }
            else{
                mpp[s[r]]--;
            }
        
        while(cnt == t.size()){
            if(r-l+1 < minlen){
                minlen = r-l+1;
                startindex = l;
            }
            mpp[s[l]]++;
            if(mpp[s[l]] > 0) cnt = cnt-1;
            l = l+1;
        }
        r++;
      }
        return startindex == -1 ? "" : s.substr(startindex,minlen);
    }
};