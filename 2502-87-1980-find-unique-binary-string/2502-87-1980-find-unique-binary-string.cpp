class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
      /*  //approach1 == tc= 0(n^2)==bitset take n time
        unordered_set<int>numbers;
        for(string &num : nums){
            numbers.insert(stoi(num,0,2)); //convert binary digit into decimal
        }
        string result ="";
        int n = nums.size();
        for(int number = 0 ; number <= pow(2,n)-1 ; number++ ){ //we can write n too instead of pow(2,n)

            if(numbers.find(number) == numbers.end()){ //did not find
              result = bitset<16>(number).to_string() ; //convertin decimal into 16bit binary then that binary
                                                        // into string

                return result.substr(16-n,n);  //extracting what we need as result index start from 0 to n-1
            }

        }
        return "";*/

        //aproach2 = tc=0(n)
         int n = nums.size();
        
        string result;
        
        for(int i = 0; i<n; i++) {
            char ch = nums[i][i];
            
            if(ch == '0'){
                 ch = '1';
                 result = result + ch;
            }
            else{
                 ch = '0';
                 result = result + ch;
            } 
        }
        
        return result;

        
    }
};