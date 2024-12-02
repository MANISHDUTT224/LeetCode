class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        string s=" "+sentence,t=" "+searchWord;
        int n=s.size();
        int m=s.find(t);
        if(m==-1){
            return -1;
        }
        return 1+count(s.begin(),s.begin()+m,' ');
    }
};