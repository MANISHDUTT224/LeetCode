class Solution {
public:
    string nearestPalindromic(string n) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        long long number=stoll(n);
        if(number<=10){
            return to_string(number-1);
        }
        if(number==11){
            return "9";
        }
        int length=n.length();
        long long lefthalf=stoll(n.substr(0,(length+1)/2));
        vector<long long>pals(5);
        pals[0]=generatepalfromleft(lefthalf-1,length%2==0);
        pals[1]=generatepalfromleft(lefthalf,length%2==0);
        pals[2]=generatepalfromleft(lefthalf+1,length%2==0);
        pals[3]=(long)pow(10,length-1)-1;
        pals[4]=(long)pow(10,length)+1;
        long long nearpal=0;
        long long mindiff=LLONG_MAX;
        for(long long c:pals){
            if(c==number){
                continue;
            }
            long long diff=abs(c-number);
            if(diff<mindiff ||(diff==mindiff && c<nearpal)){
                mindiff=diff;
                nearpal=c;
            }

        }
        return to_string(nearpal);
    }
    long long generatepalfromleft(long long lefthalf,bool isEvlen){
        long long pal=lefthalf;
        if(!isEvlen){
            lefthalf/=10;
        }
        while(lefthalf>0){
            pal=pal*10+lefthalf%10;
            lefthalf/=10;
        }
        return pal;

    }
};