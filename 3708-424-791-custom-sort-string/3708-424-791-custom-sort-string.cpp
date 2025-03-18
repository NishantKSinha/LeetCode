class Solution {
public:
    string customSortString(string order, string s) {
       /* //approach1
         int count[26] = {0};
        
        for(char &x : s)
            count[x-'a']++;
        
        string result = "";
        for(char &ch : order) {
            while(count[ch-'a']) {
                result.push_back(ch);
                count[ch-'a']--;
            }
        }
        
        //Add the characters which are not present in 'order'
        for(char &ch : s) {
            while(count[ch-'a'] > 0) {
                result.push_back(ch);
                count[ch-'a']--;
            }
        }
        
        return result;*/
        vector<int> index(26, -1);
        
        for(int i = 0; i<order.length(); i++)
            index[order[i]-'a'] = i;
        
        //comparator
        auto lambda = [&index](char &ch1, char &ch2) {
            return index[ch1-'a'] < index[ch2-'a']; //ascending
        };
        
        sort(begin(s), end(s), lambda);//o(nlogn)
        return s;
    }
};