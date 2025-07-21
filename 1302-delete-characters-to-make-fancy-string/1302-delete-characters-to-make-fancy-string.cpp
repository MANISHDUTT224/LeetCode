class Solution {
public:
    string makeFancyString(string s) {
        stack<char>st;
        int cnt=1;
        for(int i=0;i<s.size();i++){
            if(st.empty()){
                st.push(s[i]);
            }
            else if(st.top()!=s[i]){
                st.push(s[i]);
                cnt=1;
            }
            else{
                if(cnt<2){
                    cnt++;
                    st.push(s[i]);
                }
                else{
                    continue;
                }
            }
        }
        string res;
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};