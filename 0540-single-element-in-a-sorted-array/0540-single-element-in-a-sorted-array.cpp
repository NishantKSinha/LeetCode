class Solution {
public:
   
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        int n = nums.size();
        if(nums[n-1] != nums[n-2]) return nums[n-1];
        int l =1 ;
        int r = nums.size()-2;
        while(l<=r){
            int mid= (l+r)/2;
            if(nums[mid] != nums[mid-1] && nums[mid+1] != nums[mid]) return nums[mid];
            else{
                if((mid % 2 == 0 && nums[mid] == nums[mid-1]) 
                   || (mid%2 != 0 && nums[mid] == nums[mid+1])){
                    r = mid-1;
                }
                else{
                    l = mid+1;
                }
            }
        }
        return -1;
    }
};