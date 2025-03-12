class Solution {
public:
 //approach1 == using extra space
    string resultreturn(string &s){
        string temp ="";
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] != '#'){
                temp.push_back(s[i]);
            }
            else if(temp.size() > 0 && s[i] == '#'){
                temp.pop_back();
            }
        }
        return temp;
    } 
    bool backspaceCompare(string s, string t) {
        string result1 = resultreturn(s);
        string result2 = resultreturn(t);
        return result1 == result2;
    } 
  
    
};