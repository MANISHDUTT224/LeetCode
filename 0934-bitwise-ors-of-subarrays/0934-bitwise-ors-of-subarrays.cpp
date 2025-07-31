class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int>res;
        unordered_set<int>cors;
        for(int x:arr){
            unordered_set<int>nors;
            nors.insert(x);
            for(int y:cors){
                nors.insert(x|y);
            }
            res.insert(nors.begin(),nors.end());
            cors=nors;
        }
        return res.size();
    }
};