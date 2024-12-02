class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        unordered_set<string>st(wordList.begin(),wordList.end());
        q.push({beginWord,1});
        st.erase(beginWord);
        
        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(word == endWord)return steps;
            
            for(int i = 0 ; i < word.length();i++){
                char original = word[i];
                
                for(char ch = 'a'; ch <= 'z';ch++){
                    word[i] =ch; //means we are replacing character at that specific position 
                    if(st.find(word) != st.end()){
                        q.push({word,steps+1});
                        st.erase(word);
                    }
                }
                word[i] = original; //we are getting back our original word
                
            }
        }
        return 0 ;
    }
};