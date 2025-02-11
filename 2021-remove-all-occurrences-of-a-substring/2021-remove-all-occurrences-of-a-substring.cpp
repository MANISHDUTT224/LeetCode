class Solution {
public:
    vector<int>computelps(string part){
        int n=part.size();
        vector<int>lps(n,0);
        int i=1,len=0;
        while(i<n){
            if(part[i]==part[len]){
                lps[i]=len+1;
                len++;
                i++;
            }
            else{
                if(len==0){
                    lps[i]=0;
                    i++;
                }
                else{
                    len=lps[len-1];
                }
            }
        }
        return lps;
    }
    string removeOccurrences(string s, string part) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        vector<int>lps=computelps(part);
        stack<char>charStack;
        vector<int>substringindices(s.size()+1,0);
        for(int sindex=0,partindex=0;sindex<s.size();sindex++){
            char currentchar=s[sindex];
            charStack.push(currentchar);
            if(s[sindex]==part[partindex]){
                substringindices[charStack.size()]=++partindex;
                if(partindex==part.size()){
                    int remlen=part.size();
                    while(remlen!=0){
                        charStack.pop();
                        remlen--;
                    }
                
                partindex=charStack.empty()?0:substringindices[charStack.size()];
                }
            }
            else{
                if(partindex!=0){
                    partindex=lps[partindex-1];
                    charStack.pop();
                    sindex--;
                }
                else{
                    substringindices[charStack.size()]=0;
                }
            }
        }
        string result="";
        while(!charStack.empty()){
            result=charStack.top()+result;
            charStack.pop();
        }
        return result;
    }
};