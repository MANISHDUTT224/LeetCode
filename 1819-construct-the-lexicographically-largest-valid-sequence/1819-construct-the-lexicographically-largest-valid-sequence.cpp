class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
vector<int>resultsequence(n*2-1,0);
vector<bool>isNumberused(n+1,false);
findLexicographicallylargestsequence(0,resultsequence,isNumberused,n);
return resultsequence;
    }
    bool findLexicographicallylargestsequence(int currentindex,vector<int>&resultsequence,vector<bool>&isNumberused,int n){
        if(currentindex==resultsequence.size()){
            return true;
        }
        if(resultsequence[currentindex]!=0){
            return findLexicographicallylargestsequence(currentindex+1,resultsequence,isNumberused,n);
        }
        for(int numberToplace=n;numberToplace>=1;numberToplace--){
            if(isNumberused[numberToplace]){
                continue;
            }
            isNumberused[numberToplace]=true;
            resultsequence[currentindex]=numberToplace;
            if(numberToplace==1){
                if(findLexicographicallylargestsequence(currentindex+1,resultsequence,isNumberused,n)){
                    return true;
                }
            }
            else if(currentindex+numberToplace<resultsequence.size() &&resultsequence[currentindex+numberToplace]==0 ){
                resultsequence[currentindex+numberToplace]=numberToplace;
                if(findLexicographicallylargestsequence(currentindex+1,resultsequence,isNumberused,n)){
                    return true;
                }
                resultsequence[currentindex+numberToplace]=0;
            }
            isNumberused[numberToplace]=false;
            resultsequence[currentindex]=0;
        }
        return false;
    }
};