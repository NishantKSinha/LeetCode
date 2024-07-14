class Solution {
public:
    string sortSentence(string s) {
        vector<string>ans(10);
        string temp="";
        int idx = 0;
        int count =0;
        while(idx<s.size()){
            if(s[idx]== ' '){
                int pos = temp[temp.size()-1]-'0';
                temp.pop_back();
                ans[pos] = temp;
                temp.clear();
                count++;
                idx++;
            }
            else{
                temp+=s[idx];
                idx++;
            }
        }
            //for last word
              int pos = temp[temp.size()-1]-'0';
                temp.pop_back();
                ans[pos] = temp;
                temp.clear();
                count++;
                idx++;
        for(int i = 0;i<=count;i++){
            if(i == 0) continue;
            temp+=ans[i];
            temp+= ' ';
        }
        temp.pop_back();
        return temp;
    }
};