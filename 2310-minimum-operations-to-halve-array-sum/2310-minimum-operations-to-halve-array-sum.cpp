class Solution {
public:
    int halveArray(vector<int>& nums) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        double sum=0,s;
        priority_queue<double> pq(nums.begin(),nums.end());

        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            
        }
        s=sum;
        int ans=0;
        while(s>(sum/2.0)){
            double maxnum=pq.top();
            pq.pop();
            s-=(maxnum/2.0);
            pq.push(maxnum/2.0);
            ans++;
        }
        return ans;

    }
};