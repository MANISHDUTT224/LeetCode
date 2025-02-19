class Solution {
public:
    string getHappyString(int n, int k) {
        string currentString="";
        string result="";
        int indexInSortedList=0;
        generatehappy(n,k,currentString,result,indexInSortedList);
        return result;
    }
    void generatehappy(int n,int k,string &currentstring,string &result,int &indexInSortedList){
        if(currentstring.size()==n){
            indexInSortedList++;
            if(indexInSortedList==k){
                result=currentstring;
                
            }
            return;
        }
        for(char currentchar='a';currentchar<='c';currentchar++){
            if(currentstring.size()>0 && currentstring.back()==currentchar  ){
                continue;
            }
            currentstring+=currentchar;
            generatehappy(n,k,currentstring,result,indexInSortedList);
            if(result!=""){
                return;
            }
            currentstring.pop_back();
        }
    }
};