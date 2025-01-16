class Solution {
public:
 //tc == 0(n)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans;
        deque<int>dq;    //it is like a queue popfront means we are popping out from front side similarly other
        for(int i = 0 ; i < n ;i++){
            if(!dq.empty() && dq.front() <= i-k) dq.pop_front();

            while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back(); // we have to maintain decreasing order
            }
            dq.push_back(i);
            if(i >= k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};