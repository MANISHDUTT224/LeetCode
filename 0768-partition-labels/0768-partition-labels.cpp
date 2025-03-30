class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>partitionsizes;
        int partitionstart=0,partitionend=0;
        int lastoccurence[26]={0},firstoccurence[26]={0};
        for(int i=0;i<s.size();i++){
            lastoccurence[s[i]-'a']=i;
        }
        for(int i=0;i<s.size();i++){
            if(!firstoccurence[s[i]-'a']){
                firstoccurence[s[i]-'a']=i;
            }
            if(partitionend<firstoccurence[s[i]-'a']){
                partitionsizes.push_back(partitionend-partitionstart+1);
                partitionstart=i;
                partitionend=i;
            }
            partitionend=max(partitionend,lastoccurence[s[i]-'a']);
        }
        if(partitionend-partitionstart+1>0){
            partitionsizes.push_back(partitionend-partitionstart+1);
        }
        return partitionsizes;
    }
};