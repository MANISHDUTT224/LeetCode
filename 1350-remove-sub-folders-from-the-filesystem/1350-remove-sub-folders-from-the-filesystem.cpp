class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        vector<string>ans;
        ans.push_back(folder[0]);
        for(int i=1;i<folder.size();i++){
            string fold=ans.back();
            fold.push_back('/');
            if(folder[i].compare(0,fold.size(),fold)!=0){
                ans.push_back(folder[i]);
            }
        }
        return ans;
    }
};