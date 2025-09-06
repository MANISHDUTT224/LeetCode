class LRUCache {
public:
class Node{
    public:
    int key,value;
    Node *prev;
    Node *next;
    Node(int _key,int _value){
        key=_key;
        value=_value;
        prev=nullptr;
        next=nullptr;
    }
};
    int cap;
    Node *head=new Node(-1,-1);
    Node *tail=new Node(-1,-1);
    map<int,Node*>mp;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void addnode(Node* newnode){
        Node *temp=head->next;
        head->next=newnode;
        newnode->prev=head;
        newnode->next=temp;
        temp->prev=newnode;
    }
    void deletenode(Node *delnode){
        Node *delprev=delnode->prev;
        Node * delnext=delnode->next;
        delprev->next=delnext;
        delnext->prev=delprev;
    }

    int get(int key) {
        if(mp.find(key)!=mp.end()){
            Node *resnode=mp[key];
            int res=resnode->value;
            mp.erase(key);
            deletenode(resnode);
            addnode(resnode);
            mp[key]=head->next;
            return res;
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