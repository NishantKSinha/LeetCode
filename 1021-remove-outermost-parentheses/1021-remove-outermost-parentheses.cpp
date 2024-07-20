class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char>st;
        string temp;
     
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '('){
                if(st.size() > 0){
                    temp+= s[i];
                }
                st.push(s[i]);
            }
            else{
                st.pop();
                if(st.size() > 0){
                    temp+= s[i];
                }
            }
        }
        return temp;
    }
};