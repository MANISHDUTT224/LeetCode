class LRUCache {
    class Node{
        public:
        int key,value;
        Node *prev,*next;
        Node(int _key,int _value){
            key=_key;
            value=_value;
            prev=nullptr;
            next=nullptr;
        }
    };
public:
    map<int,Node*>mp;
    int cap;
    Node *head=new Node(-1,-1);
    Node *tail=new Node(-1,-1);
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void addnode(Node *newnode){
        Node *temp=head->next;
        head->next=newnode;
        newnode->prev=head;
        newnode->next=temp;
        temp->prev=newnode;
    }
    void deletenode(Node *delnode){
        Node *delprev=delnode->prev;
        Node *delnext=delnode->next;
        delnext->prev=delprev;
        delprev->next=delnext;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            Node *resnode=mp[key];
            int resvalue=resnode->value;
            mp.erase(key);
            deletenode(resnode);
            addnode(resnode);
            mp[key]=head->next;
            return resvalue;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node *existingnode=mp[key];
            mp.erase(key);
            deletenode(existingnode);
        }
        if(mp.size()==cap){
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new Node(key,value));
        mp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */