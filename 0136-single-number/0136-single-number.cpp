class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans;
       unordered_map<int,int>mpp;
        for(int i = 0 ; i < nums.size();i++){
            mpp[nums[i]]++;
        }
        for(auto it:mpp){
            if(it.second == 1) ans = it.first;
        }
        return ans;
    }
};