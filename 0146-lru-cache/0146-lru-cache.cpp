class LRUCache {
public:
 class node{
    public:
     int key;
    int value;
    node *next;
    node *prev;
    node(int _key,int _value){
        key=_key;
        value=_value;
    }

 };
   
    node *head=new node(-1,-1);
    node *tail=new node(-1,-1);
    int cap;
    map<int,node*>mp;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void addnode(node *newnode){
        node *temp=head->next;
        head->next=newnode;
        newnode->prev=head;
        temp->prev=newnode;
        newnode->next=temp;
    }
    void deletenode(node *delnode){
        node *delprev=delnode->prev;
        node *delnext=delnode->next;
        delprev->next=delnext;
        delnext->prev=delprev;
    }
    
    int get(int _key) {
        if(mp.find(_key)!=mp.end()){
            node *resnode=mp[_key];
            int res=resnode->value;
            mp.erase(_key);
            deletenode(resnode);
            addnode(resnode);
            mp[_key]=head->next;
            return res;
        }
        return -1;
    }
    
    void put(int _key, int _value) {
        if(mp.find(_key)!=mp.end()){
            node *existingnode=mp[_key];
            mp.erase(_key);
            deletenode(existingnode);
        }
        if(mp.size()==cap){
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(_key,_value));
        mp[_key]=head->next;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */