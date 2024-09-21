class Solution {
public:
    long long check(vector<int>& piles, int mid){
        long long hour = 0;
        for(int i = 0;i<piles.size();i++){
          hour = hour + ceil((double)(piles[i])/(double)(mid));
        
        }
        return hour;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low =1 ;
        int high = *max_element(piles.begin(),piles.end());
        int ans = 1e9;
        while(low<=high){
            int mid=(low+high)/2;
            long long  count = check(piles,mid);
            if(count > h) low = mid+1;
            else{
                ans = min(ans,mid);
                high = mid-1;
            }
        }
        return ans;
    }
};