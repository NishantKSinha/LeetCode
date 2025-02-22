class Solution {
public:
    int minAddToMakeValid(string s) {
       int i = 0 ;
       stack<char>st;
        
       while(i < s.size()){
         

         if( !st.empty() && st.top()=='(' && s[i] == ')'){
             st.pop();
             i++;
         } 
          
        else{
            st.push(s[i]);
         i++;
        }
       }
         return st.size();
    }
};