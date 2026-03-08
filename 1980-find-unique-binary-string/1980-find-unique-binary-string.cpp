class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int>integers;
        for(string num:nums){
            integers.insert(stoi(num,0,2));
        }
        for(int num=0;num<=nums.size();num++){
            if(integers.find(num)==integers.end()){
                string ans=bitset<16>(num).to_string();
                return ans.substr(16-nums.size());
            }
        }
        return "";
    }
};