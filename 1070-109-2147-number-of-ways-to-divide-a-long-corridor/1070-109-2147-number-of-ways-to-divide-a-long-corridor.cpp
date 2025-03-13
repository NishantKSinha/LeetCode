class Solution {
    //Approach-1 (Using simple iteration)
//T.C : O(n)
//S.C : O(n)
public:
      int mod = 1e9 + 7;
    int numberOfWays(string corridor) {
        vector<int> pos_seats;
        
        for (int i = 0; i < corridor.size(); i++) {
            if (corridor[i] == 'S') {
                pos_seats.push_back(i);
            }
        }
        
        if (pos_seats.size() % 2 || pos_seats.size() == 0)
            return 0;
        
        long long result = 1;
        int prev = pos_seats[1]; //End index of the starting subarray having 2 seats
        
        for (int i = 2; i < pos_seats.size(); i += 2) {
            int curr = pos_seats[i];
            int length = curr - prev;
            result  = (result * length) % mod;
            
            prev = pos_seats[i + 1];
        }
        
        return result;
    }
};