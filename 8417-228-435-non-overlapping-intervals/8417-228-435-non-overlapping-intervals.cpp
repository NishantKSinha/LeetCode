class Solution {
public:
static bool comparison( vector<int> a,  vector<int> b) { 
    return a[1] < b[1];
}
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
             sort(intervals.begin(), intervals.end(), comparison);
             int lasttime = intervals[0][1];
             int cnt =1;

     for(int i = 1 ; i < intervals.size();i++){
        if(intervals[i][0] >= lasttime){//in this case only we consider that equal start and endtime will not overlap
                    cnt++;
                    lasttime = intervals[i][1];
                }
             }
             int ans = intervals.size()-cnt;
             return ans;
    }
};