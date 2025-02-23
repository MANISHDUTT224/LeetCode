class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int n=arr.size();
        int ones=count(arr.begin(),arr.end(),1);
        if(ones==0){
            return {0,n-1};
        }
        if(ones%3){
            return {-1,-1};
        }
        ones/=3;
        int first=-1,second=-1,third=-1;
        int count_one=0;
        for(int i=0;i<n;i++){
            if(arr[i]==1){
                count_one++;
            }
            if(count_one==1 && first==-1){
                first=i;
            }
            else if(count_one==ones+1 && second==-1){
                second=i;
            }
            else if(count_one==2*ones+1 && third==-1){
                third=i;
            }
        }
        int i,j,k;
        for(i=first,j=second,k=third;k<n;i++,j++,k++){
            if(!(arr[i]==arr[j] && arr[j]==arr[k])){
                return {-1,-1};
            }
        }
        return {i-1,j};

    }
};