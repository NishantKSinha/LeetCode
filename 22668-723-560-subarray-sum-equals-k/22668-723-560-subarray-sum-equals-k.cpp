class Solution {
public:
    int subarraySum(vector<int>&arr, int k) {
          int target = k ;
        unordered_map<int,int>mpp; //locate sum with count of number of times appear
        int sum = 0 ;
        int cnt = 0 ;
        mpp[0] = 1;
        for(int i = 0 ; i < arr.size();i++){
            sum = sum + arr[i];
            
            int rem = sum - target;
            
            if(mpp.find(rem) != mpp.end()){ //in map it present
               cnt = cnt + mpp[rem];
            }
            
            if(mpp.find(sum) == mpp.end() || mpp.find(sum) != mpp.end() ){ //in map it not present or present
                
                mpp[sum]++ ;
            }
        }
        return cnt;
    }
};