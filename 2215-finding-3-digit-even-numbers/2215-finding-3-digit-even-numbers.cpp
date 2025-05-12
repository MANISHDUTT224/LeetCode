class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int,int>mp;
        vector<int>v;
        for(int d:digits){
            mp[d]++;
        }
        for(int i=100;i<1000;i++){
            if(i%2==0){
                int unit=i%10,tens=(i/10)%10,hundred=i/100;
                mp[unit]--;
                mp[tens]--;
                mp[hundred]--;
                if(mp[unit]>=0 && mp[tens]>=0 && mp[hundred]>=0){
                    v.push_back(i);
                }
                mp[unit]++;
                mp[tens]++;
                mp[hundred]++;

            }
        }
        return v;
    }
};