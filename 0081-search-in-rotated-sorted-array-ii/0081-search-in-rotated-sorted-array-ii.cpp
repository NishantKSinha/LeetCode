class Solution {
public:
    bool search(vector<int>& nums, int target) {
         int n = nums.size();
        int low = 0, high = n - 1;
      
        
    while (low <= high) {
        int mid = (low + high) / 2;
      
        //if mid points the target
        if (nums[mid] == target) return true;
        
          if(nums[low] == nums[mid] && nums[mid] == nums[high]){
            low++;
            high--;
              continue;
           
        }

        //if left part is sorted:
        if (nums[low] <= nums[mid]) {
            if (nums[low] <= target && target <= nums[mid]) {
                //element exists:
                high = mid - 1;
            }
            else {
                //element does not exist:
                low = mid + 1;
            }
        }
        else { //if right part is sorted:
            if (nums[mid] <= target && target <= nums[high]) {
                //element exists:
                low = mid + 1;
            }
            else {
                //element does not exist:
                high = mid - 1;
            }
        }
     
   }
    return false;
    }
};