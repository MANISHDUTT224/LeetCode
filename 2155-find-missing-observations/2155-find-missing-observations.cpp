class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int knownrollsum=0;
        for(int roll:rolls){
            knownrollsum+=roll;
        }
        int totalrollsum=mean*(rolls.size()+n);
        int unknownrollsum=totalrollsum-knownrollsum;
        int val=unknownrollsum/n;
        int rem=unknownrollsum%n;
        if(unknownrollsum<n || unknownrollsum>n*6){
            return {};
        }
        vector<int>result(n,0);
        for(int i=0;i<n;i++){
            result[i]=val+(i<rem?1:0);
        }
        return result;
    }
};