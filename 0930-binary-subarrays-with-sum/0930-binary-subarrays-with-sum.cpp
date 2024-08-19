class Solution {
public:
    int findsumm(vector<int>& nums, int goal){
        if(goal <= 0) return 0;
        int l = 0 ;
        int r =0 ;
        int ans1 = 0 ;
        int sum = 0 ;
        while(r < nums.size()){
            sum = sum + nums[r];
            while(sum > goal-1){
                sum = sum - nums[l];
                l = l+1;
            }
            ans1 = ans1 + (r -l+1);
            r = r+1;
        }
        return ans1;
    }
    int findsum(vector<int>& nums, int goal){
        if(goal < 0) return 0 ;
        int l = 0 ;
        int r =0 ;
        int ans = 0 ;
        int sum = 0 ;
        while(r < nums.size()){
            sum = sum + nums[r];
            while(sum > goal){
                sum = sum - nums[l];
                l = l+1;
            }
            ans = ans + (r -l+1);
            r = r+1;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
      int count = findsum(nums,goal);
      int count1 = findsumm(nums,goal);
        int ans = count - count1;
        return ans;
    }
};