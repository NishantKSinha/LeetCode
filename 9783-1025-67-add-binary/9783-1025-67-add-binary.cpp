class Solution {
public:
    string addBinary(string a, string b) {
        string result;

        int i = a.length()-1 , j = b.length()-1;
        int carry = 0 ;

        while(i >= 0 || j >= 0){
            int sum = carry;

           if(i >=0 ) sum += a[i--] - '0' ;  //we have to do typecast ,is to convert a character digit
                                               // ('0' or '1') into an integer (0 or 1).

            if(j >=0 ) sum += b[j--] - '0' ;

            carry = sum > 1 ? 1 : 0;
            result +=  to_string(sum % 2); // Corrected string addition

        }
        if(carry ==1) result += "1";
        reverse(result.begin(),result.end());
        return result;
    }
};