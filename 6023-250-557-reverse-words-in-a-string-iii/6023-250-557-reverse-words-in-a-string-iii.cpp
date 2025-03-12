class Solution {
public:
    string reverseWords(string s) {
       /* //approach1 == by loop
        int n = s.length();
        int i = 0 ;
        while(i < n){

            if(s[i] != ' '){
                int j = i ;

                while(j < n && s[j] != ' '){
                    j++;
                }
                reverse(s.begin() + i, s.begin()+j); //reverse krdega j ke ek piche the
                i = j ;
                i++;
            }
        }
        return s;*/

        //appproach2 == we will use tokenizer. tokenizer basically divide the string on basis of space or comma
        //  etc..by default it divide on basis of space

        stringstream ss(s); //it divide string into tokens
        string token = "";
        string result = "";

        while(ss >> token){  //putting divide string one by one into another strring for operation
              reverse(token.begin() , token.end());
              result += token + " ";
        }  

        return result.substr(0,result.size()-1); //we have to remove last space

    }
};