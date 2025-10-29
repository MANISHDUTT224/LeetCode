class Solution {
public:
    int smallestNumber(int n) {
        int noofbits=0,setbits=0;
        int temp=n;
        while(n>0){
            noofbits++;
            if(n%2!=0){
                setbits++;
            }
            n/=2;
        }
        // cout<<noofbits<<" "<<setbits<<endl;
        if(setbits==noofbits){
            return temp;
        }
        int newnum=0;

        for(int i=noofbits-1;i>=0;i--){
            newnum+=pow(2,i);
        }
       
        //cout<<newnum;
        return newnum;

    }
};