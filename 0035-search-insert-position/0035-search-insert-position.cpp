class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
     int mid  = -1 ;
        int ans = nums.size() ;
       int l = 0;
        int r = nums.size()-1;
        while(l <= r){
            int mid = (r+l)/2;
            if(nums[mid] >= target){ 
                ans = mid;
                r = mid - 1;
                
            }
            else { 
                l = mid+1;
                
             }
           
        }
        return ans;
    }
};