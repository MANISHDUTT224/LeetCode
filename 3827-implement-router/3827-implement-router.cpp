class Router {
public:
    struct Packet{
int source,destination,timestamp;
    };
deque<Packet>queue;
unordered_set<string>packetSet;
unordered_map<int,vector<int>>destMap;
string getKey(int source,int destination,int timestamp){
    return to_string(source)+"-"+to_string(destination)+"-"+to_string(timestamp);
}
void evictOldPacket(){
    if(!queue.empty()){
        Packet pkt=queue.front();
        queue.pop_front();
        packetSet.erase(getKey(pkt.source,pkt.destination,pkt.timestamp));
        auto &timestamps=destMap[pkt.destination];
        auto it=lower_bound(timestamps.begin(),timestamps.end(),pkt.timestamp);
        if(it!=timestamps.end() && *it==pkt.timestamp){
            timestamps.erase(it);
        }
        if(timestamps.empty()){
            destMap.erase(pkt.destination);
        }
    }
}
int memoryLimit_;
    Router(int memoryLimit) : memoryLimit_(memoryLimit) {}

    bool addPacket(int source, int destination, int timestamp) {
        string key = getKey(source, destination, timestamp);
        if (packetSet.count(key)) {
            return false;
        }
        packetSet.insert(key);
        queue.push_back({source, destination, timestamp});
        destMap[destination].push_back(timestamp);
        while (queue.size() > memoryLimit_) {
            evictOldPacket();
        }
        return true;
    }
    
 vector<int> forwardPacket() {
        if (queue.empty()) {
            return {};
        }
        Packet pkt = queue.front();
        queue.pop_front();
        packetSet.erase(getKey(pkt.source, pkt.destination, pkt.timestamp));
        auto& timestamps = destMap[pkt.destination];
        auto it = lower_bound(timestamps.begin(), timestamps.end(), pkt.timestamp);
        if (it != timestamps.end() && *it == pkt.timestamp) {
            timestamps.erase(it);
        }
        if (timestamps.empty()) {
            destMap.erase(pkt.destination);
        }
        return {pkt.source, pkt.destination, pkt.timestamp};
    }
    
     int getCount(int destination, int startTime, int endTime) {
        if (destMap.find(destination) == destMap.end()) {
            return 0;
        }
        const vector<int>& timestamps = destMap[destination];
        auto low = lower_bound(timestamps.begin(), timestamps.end(), startTime);
        auto high = upper_bound(timestamps.begin(), timestamps.end(), endTime);
        return high - low;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */