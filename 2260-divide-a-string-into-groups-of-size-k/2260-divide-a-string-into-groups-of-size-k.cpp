class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>ans;
        for(int i=0;i<s.size();i+=k){
             string temp=""; 
            for(int j=i;j<i+k;j++){
             
           if(j<s.size()){
            temp+=s[j];
           }
           else{
            temp+=fill;
           }
           
          
            }
             ans.push_back(temp);
        }
        return ans;
    }
};