class Solution {
public:
    int lowerbound(vector<int>& nums, int target){
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
    int upperbound(vector<int>& nums, int target){
        int mid  = -1 ;
        int ans = nums.size() ;
       int l = 0;
        int r = nums.size()-1;
        while(l <= r){
            int mid = (r+l)/2;
            if(nums[mid] > target){ 
                ans = mid;
                r = mid - 1;
                
            }
            else { 
                l = mid+1;
                
             }
           
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
       
        int lower= lowerbound(nums ,  target); 
        int upper = upperbound(nums , target);

        if(lower == nums.size() || nums[lower] != target) return {-1 , -1};
        return {lower , upper-1};
    }
};