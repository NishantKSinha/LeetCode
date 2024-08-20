class Solution {
public:
     int countlesssubarray(vector<int>&nums ,int k){
        int l =0;
        int r = 0;
        int cnt = 0;
        unordered_map<int,int>visited;
        
        while(r < nums.size()){
            visited[nums[r]]++;
            
            while(visited.size() > (k-1)){
                visited[nums[l]]--;
                if(visited[nums[l]] == 0) visited.erase(nums[l]);
                l++;
            }
            r++;
            cnt = cnt + (r-l+1);
        }
        return cnt;
    }
    int countsubarray(vector<int>&nums ,int k){
        int l =0;
        int r = 0;
        int cnt = 0;
        unordered_map<int,int>visited;
        
        while(r < nums.size()){
            visited[nums[r]]++;
            
            while(visited.size() > k){
                visited[nums[l]]--;
                if(visited[nums[l]] == 0) visited.erase(nums[l]);
                l++;
            }
            r++;
            cnt = cnt + (r-l+1);
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
     /*
     //brut forcce->tc==O(n^2)
     int cnt = 0 ;
        for(int i = 0; i < nums.size() ; i++){
            unordered_map<int,int>visited;
            for(int j = i ; j < nums.size() ; j++){
                visited[nums[j]]++;
                if(visited.size() == k) cnt++;
                if(visited.size() > k ) break;
            }
        }
        return  cnt;*/
        
        int cnt = countsubarray(nums , k);
        int cnt1 = countlesssubarray(nums,k);
        int ans = cnt - cnt1;
        return ans;
    }
};