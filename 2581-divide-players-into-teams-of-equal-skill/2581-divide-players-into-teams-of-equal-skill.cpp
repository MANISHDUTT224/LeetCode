class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        sort(skill.begin(),skill.end());
        long long ans=0;
        int l=0,r=skill.size()-1;
        int temp=0;
        while(l<r){
            if(temp>0 && skill[l]+skill[r]!=temp){
                return -1;
            }
            ans+=skill[l]*skill[r];
            temp=skill[l]+skill[r];
            l++;
            r--;
        }
        return ans;
    }
};