class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        priority_queue<pair<int,char>>maxheap;
        if(a>0){
            maxheap.push({a,'a'});
        }
        if(b>0){
            maxheap.push({b,'b'});
        }
        if(c>0){
            maxheap.push({c,'c'});
        }
        string result;
        while(!maxheap.empty()){
            pair<int,char>top1=maxheap.top();
            maxheap.pop();
            int count1=top1.first;
            char char1=top1.second;
            int length=result.size();
            if(length>=2 && result[length-1]==char1 && result[length-2]==char1){
                if(maxheap.empty()){
                    break;
                }
                pair<int,char> top2=maxheap.top();
                maxheap.pop();
                int count2=top2.first;
                char char2=top2.second;
                result+=char2;
                count2--;
                if(count2>0){
                    maxheap.push({count2,char2});
                }
                maxheap.push({count1,char1});
            }
            else{
                result+=char1;
                count1--;
                if(count1>0){
                    maxheap.push({count1,char1});
                }
            }
        }
        return result;
    }
};