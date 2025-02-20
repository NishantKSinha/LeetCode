class Solution {
public:
//sliding window == tc = o(N)
    int minSubArrayLen(int target, vector<int>& nums) {
       int i = 0 , j = 0 ;
       int sum = 0 ;
       int minl = INT_MAX;

       while(j < nums.size()){
          sum = sum + nums[j];

           while(sum >= target){
               minl = min(minl , j-i+1);
               
               sum = sum-nums[i];

               i++;

           }
           j++;
       }
       return minl== INT_MAX ? 0 : minl;
    }
};