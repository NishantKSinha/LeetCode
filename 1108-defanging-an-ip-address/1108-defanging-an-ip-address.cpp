class Solution {
public:
    string defangIPaddr(string address) {
        string ans;
        int idx=0;
        while(idx < address.size()){
            if(address[idx] == '.'){
                ans = ans+"[.]";
            }
            else{
                ans = ans+address[idx];
            }
            idx++;
        }
        return ans;
    }
};