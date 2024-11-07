class Solution {
public:
    int halveArray(vector<int>& nums) {
        double sum=0,s;
        priority_queue<double> pq;

        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            pq.push(nums[i]);
        }
        s=sum;
        int ans=0;
        while(!pq.empty()){
            double ele=pq.top();
            pq.pop();
            s=s-(ele/2);
            if(s<=sum/2){
                ans++;
                break;
            }
            ans++;
            pq.push(ele/2);
        }
        return ans;

    }
};