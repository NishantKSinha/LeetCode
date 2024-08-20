class Solution {
public:
    int countoddless(vector<int>&nums , int k){
        int r = 0;
        int l = 0 ;
        int ans = 0 ;
        int oddcount = 0 ;
        while(r < nums.size()){
            if(nums[r] % 2 == 1){
                oddcount++;
            }
            while(oddcount > (k-1)){
                if(nums[l] % 2 == 1){
                    l++;
                    oddcount--;
                }
                else{
                    l++;
                }
            }
            ans = ans + (l-r+1);
            r++;
        }
        return ans;
    }
    int countodd(vector<int>&nums , int k){
        int r = 0;
        int l = 0 ;
        int ans = 0 ;
        int oddcount = 0 ;
        while(r < nums.size()){
            if(nums[r] % 2 == 1){
                oddcount++;
            }
            while(oddcount > k){
                if(nums[l] % 2 == 1){
                    l++;
                    oddcount--;
                }
                else{
                    l++;
                }
            }
            ans = ans + (l-r+1);
            r++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int cnt = countodd(nums , k);
        int cnt1 = countoddless(nums , k);
        int ans = cnt1 - cnt;
        return ans;
    }
};