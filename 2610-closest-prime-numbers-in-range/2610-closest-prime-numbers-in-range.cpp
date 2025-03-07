class Solution {
public:
    bool isprime(int n){
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int>primenumbers;
       
        for(int i=left;i<=right;i++){
             if(i%2==0  && i>2 || i<=1){
            continue;
        }
            if(isprime(i)){
                if(!primenumbers.empty() && i<=primenumbers.back()+2){
                    return {primenumbers.back(),i};
                }
                primenumbers.push_back(i);
            }
        }
        if(primenumbers.size()<2){
            return {-1,-1};
        }
        int mindiff=INT_MAX;
        vector<int>closestpair={-1,-1};
        for(int i=1;i<primenumbers.size();i++){
            int diff=primenumbers[i]-primenumbers[i-1];
            if(diff<mindiff){
                mindiff=diff;
                closestpair={primenumbers[i-1],primenumbers[i]};
            }
        }
        return closestpair;
    }
};