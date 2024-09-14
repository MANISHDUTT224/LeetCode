class Solution {
public:
    string removeStars(string s) {
        stack<char> s1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='*'){
                s1.pop();
            }
            else{
                s1.push(s[i]);
            }
        }
        string a;
        while(!s1.empty()){
            char it=s1.top();
            a+=it;
            s1.pop();
            
        }
        reverse(a.begin(),a.end());
        return a;
    }
};