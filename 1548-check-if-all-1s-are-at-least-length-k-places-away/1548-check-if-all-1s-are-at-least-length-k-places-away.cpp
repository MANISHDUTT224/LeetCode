class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int firstappearance=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1 && firstappearance==-1){
                firstappearance=i;
            }
            else if(nums[i]==1){
                cout<<i-firstappearance<<endl;
                if(i-firstappearance<=k){
                    return false;
                }
                firstappearance=i;
            }
            
        }      
        return true;
    }
};