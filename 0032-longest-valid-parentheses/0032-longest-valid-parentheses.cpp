class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        int maxlen=0;
        st.push(-1);
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(c=='('){
                st.push(i);
            }
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                maxlen=max(maxlen,i-st.top());
            }
        }
        return maxlen;
    }
};