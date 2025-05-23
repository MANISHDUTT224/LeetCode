class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>count(101,0);
        for(auto num:nums){
            count[num]++;

        }
        for(int i=1;i<=100;i++){
            count[i]+=count[i-1];
        }
        vector<int>res;
        for(auto num:nums){
            res.push_back((num==0)?0:count[num-1]);
        }
        return res;
    }
};