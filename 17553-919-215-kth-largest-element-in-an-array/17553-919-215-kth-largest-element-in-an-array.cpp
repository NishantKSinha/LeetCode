class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      /*  sort(nums.begin(),nums.end());
        int num  ;
        int count = 0 ;
          if(nums.size() == 1){
            num = nums[nums.size()-1];
        }
        for(int i = nums.size()-1 ; i > 0 ; i--){
            if(nums[i] != nums[i-1] || nums[i] == nums[i-1]){
                count++;
            }
            if(count == k){
                num = nums[i];
            }
            if(k == nums.size()){
                num = nums[0];
            }
        }
        return num; */
        
        //by priority queue
        priority_queue<int>pq(nums.begin(),nums.end());
        int ans = 0 ;
        while(k!=0){
            ans=pq.top();
            pq.pop();
            k--;

        }
        return ans;

    }
};