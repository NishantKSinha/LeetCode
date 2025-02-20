class Solution {
public:
     //tc = nlogn + n
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;

        if(intervals.size() == 0 ) return ans;
         
        int n = intervals.size();
        sort(intervals.begin(),intervals.end()); //it will automatacially sort on basis of start time

        for(int i = 0 ; i < n ; i++){

            if(ans.empty()  || ans.back()[1] < intervals[i][0]){
                ans.push_back(intervals[i]);
            }
            else{   //taking last element of pair for merging
                ans.back()[1] = max(ans.back()[1] , intervals[i][1]);

            }

        }
        return ans;

    }
};