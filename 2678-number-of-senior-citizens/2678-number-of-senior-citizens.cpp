class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for(auto i : details){
            int a = i[11] - '0';
            int b = i[12] - '0';
          if((a*10 + b) > 60){
              ans++;
          }  
        }
        return ans;
    }
};