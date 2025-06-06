class Solution {
public:
    string robotWithString(string s) {
     unordered_map<char,int>cnt;
     for(char c:s){
        cnt[c]++;
     }
     char minc='a';
     stack<char>stk;
     string res;
     for(char c:s){
        stk.emplace(c);
        cnt[c]--;
        while(minc!='z' && cnt[minc]==0){
            minc++;
        }
        while(!stk.empty() && stk.top()<=minc){
            res.push_back(stk.top());
            stk.pop();
        }

     }
     return res;
    }
};