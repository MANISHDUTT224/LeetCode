class Solution {
public:
    int findTheLongestSubstring(string s) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        int n=s.length();
        int mask=0,maxlength=0;
        vector<int>pos(32,-1);
        pos[0]=0;
        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                mask^=(1<<0);
            }
            else if(s[i]=='e'){
                mask^=(1<<1);
            }
            else if(s[i]=='i'){
                mask^=(1<<2);
            }
            else if(s[i]=='o'){
                mask^=(1<<3);
            }
            else if(s[i]=='u'){
                mask^=(1<<4);
            }
            if(pos[mask]!=-1){
                maxlength=max(maxlength,i+1-pos[mask]);
            }
            else{
                pos[mask]=i+1;
            }
        }
        return maxlength;
    }
};