class Solution {
public:
    string largestGoodInteger(string num) {
        int maxnum=INT_MIN;
        for(int i=1;i<num.size();i++){
            if(num[i-1]==num[i] && num[i]==num[i+1]){
                int temp=num[i]-'0';
                maxnum=max(temp,maxnum);
            }
        }
        if(maxnum==INT_MIN){
            return "";
        }
        return to_string(maxnum)+to_string(maxnum)+to_string(maxnum);
    }
};