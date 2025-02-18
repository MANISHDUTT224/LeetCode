class Solution {
public:
    string smallestNumber(string pattern) {
        string result="";
        buildSequences(0,0,pattern,result);
        reverse(result.begin(),result.end());
        return result;
    }
    int buildSequences(int currentIndex,int currentCount,string pattern,string &result){
        if(currentIndex!=pattern.size()){
            if(pattern[currentIndex]=='I'){
                buildSequences(currentIndex+1,currentIndex+1,pattern,result);
            }
            else{
                currentCount=buildSequences(currentIndex+1,currentCount,pattern,result);
            }
        }
        result+=to_string(currentCount+1);
        return currentCount+1;
    }
};