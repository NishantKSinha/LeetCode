class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int N = arr.size();
        vector<int> ans(N);
    priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end());
    unordered_map<int, int> rankMap;
    
    int rank = 1;
    while (!pq.empty()) {
        int current = pq.top();
        pq.pop();
        // Assign rank if not already assigned
        if (rankMap.find(current) == rankMap.end()) {
            rankMap[current] = rank;
            rank++;
        }
    }
    
    // Replace elements with their rank
    for (int i = 0; i < N; i++) {
        ans[i] = rankMap[arr[i]];
    }
    
    return ans;
    }
};