class Solution {
public:
    vector<vector<int>> ans;
    void printf(vector<int> &result , int ind ,vector<int>& nums,int n){
        if(ind >= n){
           ans.push_back(result);
            return ;
        }
        result.push_back(nums[ind]);
        printf(result , ind +1 , nums,n);
        result.pop_back();
        
        printf(result , ind +1 , nums , n);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> result;
        int n = nums.size();
      /*  for (int i = 0; i < (1 << n); i++) {  //pow(2,n) == 1 << n
            vector<int> subset;
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) > 0) {
                    subset.push_back(nums[j]);
                }
            }
            result.push_back(subset);
        }
        return result;*/
        
       printf(result , 0 , nums ,n);
        return ans;
    }
};