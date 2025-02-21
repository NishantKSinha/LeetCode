class Solution {
public: //solution -- https://www.youtube.com/watch?v=yzlQj0LR7m8
    vector<int> plusOne(vector<int>& digits) {
          //we will modify in same array

          int idx = digits.size()-1;

          while(idx >= 0){

            if(digits[idx] == 9){
                digits[idx] = 0;
            }
            else{
                digits[idx] += 1;
                return digits;
            }
            idx -- ;
          } 
          digits.insert(digits.begin(),1);  // this is for -> 9 , 99 , 999 .......
          return digits;
    }
};