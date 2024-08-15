class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int>mp;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){
                mp[bills[i]]++;
            }
            else if(bills[i]==10){
                if(mp[5]<1){
                    return false;
                }
                else{
                    mp[5]--;
                }
                mp[10]++;
            }
            else{
                if(!((mp[10]>=1 && mp[5]>=1) || mp[5]>=3)){
                    return false;
                }
                else{
                    if(mp[10]>=1 && mp[5]>=1){
                        mp[10]--;
                        mp[5]--;
                    }
                    else{
                        mp[5]-=3;
                    }
                }
            }
        }
        return true;
    }
};