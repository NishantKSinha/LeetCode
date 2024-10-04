class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        for(int i = 1 ; i < n;i++){
            if(nums[i] < nums[i-1]) count++;
        }
        //check for cyclic i.e. between last and first element 
        if(nums[n-1] > nums[0]) count++;
        
        if(count <=1) return true;  //<=1 bcz for taking array whose all elements are equal
        return false;
    }
};