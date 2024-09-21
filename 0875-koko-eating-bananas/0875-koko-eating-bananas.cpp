class Solution {
public:
/*int max(vector<int>& piles){
    int maxi = piles[0];
    for(int i = 1 ; i < piles.size();i++){
        if(maxi < piles[i]) maxi = piles[i];
    }
    return maxi;
}*/
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
        
        while(low<=high){
            int mid=(low+high)/2;
            long long  count = check(piles,mid);
            if(count > h) low = mid+1;
            else{
                
                high = mid-1;
            }
        }
        return low;
    }
};