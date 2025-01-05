class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;

        if(intervals.size() == 0 ) return ans;
         
        int n = intervals.size();
        sort(intervals.begin(),intervals.end()); //it will automatacially sort on basis of start time

        for(int i = 0 ; i < n ; i++){

            if(ans.empty()){
                ans.push_back(intervals[i]);
            }
            else{
                vector<int>&v = ans.back(); //taking last element or pair or vector which insert
                //we arre taking by referrence bcz if its overlap we have to change 
                
                int y = v[1];

                if(intervals[i][0] <= y){
                    v[1] = max(intervals[i][1] , y);
                }
                //not overlapping
                else{
                    ans.push_back(intervals[i]);
                }

            }

        }
        return ans;

    }
};