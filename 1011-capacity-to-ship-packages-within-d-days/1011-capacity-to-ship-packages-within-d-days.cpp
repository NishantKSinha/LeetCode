class Solution {
public:
    int check(vector<int>& weights,int mid){
        int sum = 0;
        int noofday = 1;
        for(int i = 0 ; i < weights.size() ; i++){
            if(sum + weights[i]<= mid) sum = sum + weights[i];
            else{
                noofday++;
                sum =  weights[i];
            }
        }
        return noofday;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low =  *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);  
        int ans = 1e9;
        while(low <= high){
            int mid = (low + high)/2;
            int count = check(weights , mid);
            if(count > days) low = mid +1;
            else {
                ans = min(ans,mid);
                high = mid-1;
                
            }
        }
        return ans;
    }
};