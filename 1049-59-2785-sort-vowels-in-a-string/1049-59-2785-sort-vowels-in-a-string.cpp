class Solution {
public:
   bool isVowel(char ch){ //we will not use "&"  bcz we are changing into lower case
        ch = tolower(ch);

       return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
   }
    string sortVowels(string s) {
      string temp = "";

      for(char &ch : s){
        if(isVowel(ch)){
            temp.push_back(ch);
        }
      }

      sort(temp.begin(),temp.end()); //sort on basis of ascii value .. capital letter come first
      int j = 0 ;

      for(int i = 0 ; i < s.size();i++){

        if(isVowel(s[i])){
            s[i] = temp[j];
            j++;
        }
      }
      return s;
    }
};