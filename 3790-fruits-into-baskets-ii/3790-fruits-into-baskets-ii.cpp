class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int count=0;
        vector<bool>used(fruits.size(),false);
        for(int i=0;i<fruits.size();i++){
            bool placed=false;
            for(int j=0;j<baskets.size();j++){
                if(!used[j] && baskets[j]>=fruits[i]){
                    used[j]=true;
                    placed=true;
                    break;
                }
            }
            if(!placed){
                count++;
            }
        }
        return count;
    }
};