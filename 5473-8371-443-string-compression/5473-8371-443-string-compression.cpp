class Solution {
public:
    int compress(vector<char>& chars) {
        //there is more than 10 characters too so we cannot directly count and write

        int n = chars.size();
        int index = 0;
        int i = 0 ;

        while(i < n){
            char curchar = chars[i];
            int count = 0 ;
            //find count of duplicate
            while(i < n && curchar == chars[i]){
                count++;
                i++;
            }
            //Now do the assign work for alphabet
            chars[index] = curchar;
            index++;
            //now do assign work for alphabet  count == we have to assign only for greater than 1 see examples
            if(count > 1){
                string countchar = to_string(count); // convert integer to string
                //now iterate bcz it has more than one char if length is greater thsn 9
                for(char &ch : countchar){
                    chars[index] = ch;
                    index++;
                }
            }
        }
        return index; //if we have return value-> return char.substr(0,index)
    }
};