class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int r = 0 ;
        int count = 0 ;
        int maxlen = 0 ;
        while(r < nums.size()){
            if(nums[r] == 0) count++;
            if(count > k){
                if(nums[l] == 0) count--;
                l++;
            }
            if(count<=k){
                int len = r-l+ 1;
                maxlen = max(len , maxlen);
            }
            r++;
        }
        return maxlen;
    }
};