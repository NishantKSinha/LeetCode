class Solution {
public:
    string smallestSubsequence(string s) {
        string result = "";
        vector<bool>visit(26,false);
        vector<int>take(26);
        int n = s.size();

        for(int i = 0 ; i < n ; i++){
            char ch = s[i];
            take[ch-'a'] = i;
        }
        for(int i = 0 ; i <n ; i++){
            char ch = s[i];
            int idx = ch-'a';

            if(visit[idx] == true) continue;

            while(result.size() > 0 && result.back() > ch && take[result.back()-'a'] > i){
                visit[result.back()-'a'] = false;
                result.pop_back();
            }
            result.push_back(s[i]);
            visit[ch-'a'] = true;
        }
        return result;
    }
};