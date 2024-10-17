class Solution {
public:
    int maximumSwap(int num) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        unordered_map<char,int> mp;
        string nums=to_string(num);
        string nums2=nums;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=i;
        }
        sort(nums2.rbegin(),nums2.rend());
        int i=0,count=0;
        while(i<nums.size() && count<1){
            if(nums[i]==nums2[i]){
                i++;
            }
            else{
                swap(nums[mp[nums2[i]]],nums[i]);
                count=1;
            }
        }
        return stoi(nums);
    }
};