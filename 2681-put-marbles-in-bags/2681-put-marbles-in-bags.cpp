class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n=weights.size();
        vector<int>pairweights(n-1,0);
        for(int i=0;i<n-1;i++){
            pairweights[i]=weights[i]+weights[i+1];
        }
        sort(pairweights.begin(),pairweights.end());
        long long answer=0;
        for(int i=0;i<k-1;i++){
            answer+=pairweights[n-2-i]-pairweights[i];
        }
        return answer;
    }
};