class Solution {
public:
 // approach == we can solve it using kdanes too but its not so much intutive 
 
 //apply normal observation ===  if all elements positive and even number of elements are negative->whole array element will be answer
 //if there is 0 in array -> then ignore the zero
 //if there is odd number of negative eleement -> we will ignore any one of them and get the result
 
 //we will use suffix(start from n-1) and prefix(star from 0)  == tc=0(N)
    int maxProduct(vector<int>& nums) {
        int prefix = 0 , suffix = 0;
        int prod= 1;

        int ans = INT_MIN;

        int i = 0 , j = nums.size()-1;

        while(i < nums.size() && j >=0){

            if(prefix == 0) prefix =1; //ignorning 0 case
            if(suffix == 0) suffix =1;

            prefix = prefix * nums[i];
            suffix = suffix * nums[j];

             ans = max(ans, max(suffix,prefix) );

            i++;
            j--;

        }
        return ans;
       
    }
};