class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        sort(folder.begin(),folder.end());
        vector<string>ans;
        ans.push_back(folder[0]);
        for(int i=1;i<folder.size();i++){
            string lastfolder=ans.back();
            lastfolder.push_back('/');
            if(folder[i].compare(0,lastfolder.size(),lastfolder)!=0){
                ans.push_back(folder[i]);
            }
        }
        return ans;
    }
};