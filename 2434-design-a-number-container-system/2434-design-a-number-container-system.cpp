class NumberContainers {
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        indicesTonumbers[index]=number;
        numberToindices[number].push(index);
    }
    
    int find(int number) {
        if(numberToindices.find(number)==numberToindices.end()){
            return -1;
        }
       auto &minheap=numberToindices[number];
       while(!minheap.empty()){
        int index=minheap.top();
        if(indicesTonumbers[index]==number){
            return index;
        }
        minheap.pop();
       }
       return -1;
    }
private:
     unordered_map<int,priority_queue<int,vector<int>,greater<int>>> numberToindices;
     unordered_map<int,int>indicesTonumbers;


};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */