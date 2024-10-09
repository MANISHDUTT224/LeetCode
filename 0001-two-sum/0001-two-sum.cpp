class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        int l=0,r=arr.size()-1;
        vector<int>res;
        vector<pair<int,int>>v;
        for(int i=0;i<arr.size();i++){
            v.push_back({arr[i],i});
        }
        sort(v.begin(),v.end());
        while(l<=r){
            if(v[l].first+v[r].first==target){
                return {v[l].second,v[r].second};
            }
            else if(v[l].first+v[r].first<target){
                l++;
            }
            else{
                r--;
            }
        }   
        return {-1,-1};
    }
};