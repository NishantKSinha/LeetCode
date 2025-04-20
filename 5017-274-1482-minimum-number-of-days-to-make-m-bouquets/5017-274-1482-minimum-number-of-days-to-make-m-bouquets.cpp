class Solution {
public:
    bool test(vector<int>& arr, int mid,int m, int k){
        int cnt = 0;
        int duplk = k;
        for(int i = 0 ; i < arr.size();i++){
            if(mid >= arr[i]){
                duplk--;
                if(duplk == 0){
                    cnt++;
                    duplk = k; 
                }
            }
            else duplk = k;
        }
        if(cnt >= m) return true;
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
       
       // if(m*n > bloomDay.size()) return -1;  ==> we cannot do this bcz multiplication of m and k in some cases goes out of bound
        int l = *min_element(bloomDay.begin(), bloomDay.end());
        int h = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = INT_MAX;
        while(l <= h){
            int mid =(l+h)/2;
            if(test(bloomDay,mid,m,k) == true){
                ans = min(ans,mid);
                h = mid-1;
            }
            else l = mid+1;
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};