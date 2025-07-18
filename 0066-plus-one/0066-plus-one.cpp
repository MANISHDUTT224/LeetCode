class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        int carry=1;
        for(int i=digits.size()-1;i>=0;i--){
            digits[i]+=carry;
            carry=digits[i]/10;
            digits[i]%=10;
        }
        while(carry>0){
            digits.insert(digits.begin(),carry%10);
            carry/=10;
        }
        return digits;
    }
};