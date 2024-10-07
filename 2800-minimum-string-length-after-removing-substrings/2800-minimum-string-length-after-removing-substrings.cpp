class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        for(int i=0;i<s.size();i++){
            char cur_char=s[i];
            if(st.empty()){
                st.push(cur_char);
                continue;
            }
            else if(cur_char=='B' && st.top()=='A'){
                st.pop();
            }
            else if(cur_char=='D' && st.top()=='C'){
                st.pop();
            }
            else{
                st.push(cur_char);
            }
        }
        return st.size();
    }
};