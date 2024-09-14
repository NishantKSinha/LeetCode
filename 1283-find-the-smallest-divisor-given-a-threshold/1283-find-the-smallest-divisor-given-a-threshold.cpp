class Solution {
public:
    int sumByD(vector<int> &nums, int div) {
    int n = nums.size(); //size of array
    //Find the summation of division values:
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ceil(double(nums[i]) /double(div));
    }
    return sum;
}

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size(); 
    if (n > threshold) return -1;//this not necessary bcz ques say it has definitely a output
    int low = 1, high = *max_element(nums.begin(), nums.end());
        int ans = 1e9;

    //Apply binary search:
    while (low <= high) {
        int mid = (low + high) / 2;
        if (sumByD(nums, mid) <= threshold) {
            high = mid - 1;
            ans = min(ans,mid);
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
    }
};