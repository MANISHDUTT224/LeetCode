class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int oc=0,ec=0;
        for(int pos:position){
            if(pos%2==0){
                ec++;
            }
            else{
                oc++;
            }
        }
        return min(ec,oc);
    }
};