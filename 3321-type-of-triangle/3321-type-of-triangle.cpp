class Solution {
public:
    string triangleType(vector<int>& nums) {
        set<int>st;
        int s=1;
        for(int i=0;i<nums.size();i++){
            if(st.empty() || st.find(nums[i])==st.end()){
                st.insert(nums[i]);
               
            }
            else{
            s++;
            }
        }
        if(!(nums[0]+nums[1]>nums[2] && nums[1]+nums[2]>nums[0] && nums[0]+nums[2]>nums[1])){
            return "none";
        }
        cout<<s<<endl;
        if(s==3){
            return "equilateral";
        }
        if(s==1){
            return "scalene";
        }
    
        return "isosceles";
    }
};