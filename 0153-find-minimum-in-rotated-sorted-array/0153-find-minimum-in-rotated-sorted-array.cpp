class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0 ;
        int high = nums.size()-1;
        int ans = 1e9;
       while (low <= high) {
        int mid = (low + high) / 2;

        

        //if left part is sorted:
        if (nums[low] <= nums[mid]) {
           ans = min(ans,nums[low]);
            low = mid+1;
        }
        else { //if right part is sorted:
            ans = min(ans,nums[mid]);
            high = mid-1;
         }
    }
    return ans;
        
    }
};