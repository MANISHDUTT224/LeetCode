class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int knownrollsum=0;
        for(int roll:rolls){
            knownrollsum+=roll;
        }
        int totalrollsum=mean*(rolls.size()+n);
        int unknownrollsum=totalrollsum-knownrollsum;
        if(unknownrollsum<n || unknownrollsum>6*n){
            return {};
        }
        int value=unknownrollsum/n;
        int extra=unknownrollsum%n;
        vector<int>result(n,0);
        for(int i=0;i<n;i++){
            result[i]=value+(i<extra?1:0);
        }
        return result;
    }
};