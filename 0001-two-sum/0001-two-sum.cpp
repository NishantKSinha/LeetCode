class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
           //TC = O(N*LOGN) == BEST CASE , WORST CASTE =- O(N*N)
         map<int,int>mpp;
         for(int i = 0 ; i < nums.size();i++){
            int num = nums[i];
            int moreneeded = target - nums[i];
            if(mpp.find(moreneeded) != mpp.end()){
                return {mpp[moreneeded],i};
            }
            else{       //simply put in map that element
                 mpp[num] = i;
            }
        }
           return {-1,-1};
    }
        
    };