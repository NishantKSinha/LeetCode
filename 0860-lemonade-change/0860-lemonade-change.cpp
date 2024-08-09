class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fivecount = 0 ;
        int tencount = 0 ;
        for(int i = 0 ; i < bills.size() ; i++){
            
            if(bills[i] == 5){
                fivecount = fivecount + 1;
            }
            else if(bills[i] == 10){
                if(fivecount != 0){
                  tencount = tencount + 1 ;
                  fivecount = fivecount - 1;  
                }   
                else{
                    return false;
                }
                
            }
            else{
                if(fivecount != 0 && tencount != 0){
                    fivecount = fivecount -1 ;
                    tencount = tencount - 1;
                }
                else if(fivecount >= 3){
                    fivecount = fivecount -3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};