class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int>ans(n,0);
        int ballstoleft=0,movestoleft=0,ballstoright=0,movestoright=0;
        for(int i=0;i<n;i++){
            ans[i]+=movestoleft;
            ballstoleft+=boxes[i]-'0';
            movestoleft+=ballstoleft;
            int j=n-i-1;
            ans[j]+=movestoright;
            ballstoright+=boxes[j]-'0';
            movestoright+=ballstoright;
        }
        return ans;
    }
};