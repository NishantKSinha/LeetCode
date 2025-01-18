class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int gk; //Initialization of gk:The gk variable is declared as a class member and initialized in the constructor.
    KthLargest(int k, vector<int>& nums) {
        gk = k; // Since gk is a class member, it can be accessed in both the constructor and add method.
        for(int i = 0 ; i< nums.size();i++){
            pq.push(nums[i]);

            if(pq.size()> k){
                pq.pop();
            }
        }
    }

    int add(int val) {
        pq.push(val);
        if(pq.size() > gk){
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */