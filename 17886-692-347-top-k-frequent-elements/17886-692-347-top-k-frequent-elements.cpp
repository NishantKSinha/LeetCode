class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
          // Step 1: Count frequencies using unordered_map
        unordered_map<int, int> freqMap;
        for (int i = 0 ; i <nums.size();i++) {
            freqMap[nums[i]]++;
        }

        // Step 2: Use a min-heap to store top k frequent elements
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for (auto x : freqMap) {
            minHeap.push(make_pair(x.second,x.first));
            if (minHeap.size() > k) {
                minHeap.pop(); // Remove the least frequent element
            }
        }

        // Step 3: Extract the elements from the heap
        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return result;
    }
};