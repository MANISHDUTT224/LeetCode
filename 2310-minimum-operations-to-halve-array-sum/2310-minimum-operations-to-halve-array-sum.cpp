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
        while(s>=sum/2.0){
            double maxnum=pq.top();
            pq.pop();
            s-=(maxnum/2.0);
            pq.push(maxnum/2.0);
            ans++;
        }
        return ans;

    }
};