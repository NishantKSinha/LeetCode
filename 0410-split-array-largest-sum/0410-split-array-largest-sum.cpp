class Solution {
public:
    int find(vector<int>& nums, int mid){
        int noofpair = 1;
        int sum = 0;
        for(int i =0 ; i<nums.size();i++){
            if(sum + nums[i] <= mid){
                sum += nums[i];
            }
            else{
                noofpair++;
                sum = nums[i];
            }
        }
        return noofpair;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        int ans = 1e9;
        while(low<=high){
            int mid =(low+high)/2;
            int partition = find(nums,mid);
            if(partition > k){
                low = mid + 1;
            }
            else{
                high = mid-1;
                ans = min(ans,mid);
            }
        }
        return ans;
    }
};