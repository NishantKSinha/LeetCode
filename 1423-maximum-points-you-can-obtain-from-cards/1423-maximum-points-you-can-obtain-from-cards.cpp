class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
      int l = 0 ;
      int r = cardPoints.size()-1;
      int lsum = 0 ;
      int rsum = 0 ;
      int maxsum = 0 ;

      for(int i = 0 ; i < k ; i++){
          lsum = lsum + cardPoints[i];
          maxsum = lsum;
      }
      for(int i = k-1 ; i >= 0 ; i--){
        lsum = lsum - cardPoints[i];
        rsum = rsum + cardPoints[r];
        r--; 
         maxsum = max(maxsum , lsum + rsum);
      }
       return maxsum;
    }
};