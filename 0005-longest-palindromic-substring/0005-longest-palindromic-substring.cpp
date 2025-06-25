class Solution {
public:
int end=0,start=0;
    string longestPalindrome(string s) {
        int n=s.size();
        helper(s,0,n);
        return s.substr(start,end-start+1);
    }
    void helper(string s,int i,int n){
        if(i>=n){
            return;
        }
        int left=i,right=i;
        while(right<n-1 && s[right]==s[right+1]){
            right++;
        }
        i=right;
        while(left>0 && right<n-1 && s[left-1]==s[right+1]){
            left--;
            right++;
        }
        if(end-start<right-left){
            start=left;
            end=right;
        }
        helper(s,++i,n);
    }
};