class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int maxfreq=1;
        map<int,int>mp;
        int smallesteven=INT_MAX;
        for(auto num:nums){
            if(num%2==0){
                mp[num]++;
                maxfreq=max(maxfreq,mp[num]);
               
            }
        }
        for(auto it:mp){
            if(it.second==maxfreq){
                smallesteven=min(smallesteven,it.first);
            }
        }
        return smallesteven==INT_MAX?-1:smallesteven;

    }
};