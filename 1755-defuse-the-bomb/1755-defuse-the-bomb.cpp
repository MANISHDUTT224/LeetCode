class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> res;
        int n=code.size();
        vector<int> ans(n,0);
        if(k==0){
            return ans;
        }
        else if(k>0){
            int wsum=accumulate(code.begin()+1,code.begin()+k+1,0);
            ans[0]=wsum;
            for(int l=1,r=k+1;l<n;l++,r++){
                wsum+=-code[l]+code[r%n];
                ans[l]=wsum;
            }
            return ans;
        }
        else{
            k=-k;
            int wsum=accumulate(code.end()-k,code.end(),0);
            ans[0]=wsum;
            for(int r=0,l=n-k;r<n-1;r++,l++){
                wsum+=-code[l%n]+code[r];
                ans[r+1]=wsum;
            }
            return ans;
        }
    }

};