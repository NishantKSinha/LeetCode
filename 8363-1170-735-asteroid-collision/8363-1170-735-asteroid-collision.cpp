class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        int i = 0 ;
        int n = asteroids.size();
        while(i < n){
            if(asteroids[i] >= 0) {
               ans.push_back(asteroids[i]);
               i++;    
            }
            else {
                while(!ans.empty() && ans.back()>0 && ans.back() < abs(asteroids[i])){
                    ans.pop_back();
                }
            
                if(!ans.empty() && ans.back() == abs(asteroids[i])){
                    ans.pop_back();
                
                }
                 else if (ans.empty() || ans.back()<0 ){
                    ans.push_back(asteroids[i]);
                    
                }
              
                i++;
            }
           
        }
           return ans;
    }
};