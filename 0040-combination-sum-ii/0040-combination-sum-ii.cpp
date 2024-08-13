class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int>ds;
        findcomb(0,target,candidates,ans,ds);
        return ans;
    }
    void findcomb(int ind,int target,vector<int> &arr,vector<vector<int>> &ans,vector<int>&ds){
        if(target==0){
            ans.push_back(ds);
            return;
        }
        else{
            for(int i=ind;i<arr.size();i++){
                if(i>ind && arr[i]==arr[i-1]){continue;}
                if(target<arr[i]){
                    break;
                }
                ds.push_back(arr[i]);
                findcomb(i+1,target-arr[i],arr,ans,ds);
                ds.pop_back();
            }
        }
    }

};
