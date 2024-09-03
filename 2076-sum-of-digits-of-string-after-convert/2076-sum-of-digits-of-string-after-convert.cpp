class Solution {
public:
    int transform(int num){
        int sum=0;
        while(num>0){
            
            sum+=num%10;
            num/=10;
        }
        return sum;
    }


    int getLucky(string s, int k) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        string str;
        for(auto &c:s){
            str+=to_string((c-'a')+1);
        }
        int sum=0;
        for(auto &digits:str){
            sum+=digits-'0';
        }
        for(int i=1;i<k;i++){
            sum=transform(sum);
        }
        
        return sum;

    }
};