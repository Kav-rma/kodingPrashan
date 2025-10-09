#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;



class Node{
public:
    int key,val;
    Node* next;
    Node* prev;

    Node(int k, int v){
        key = k;
        val = v;
        next = prev = NULL;
    }
};

class LRUCache {
    //Creating Dummy node so reduce NULL cases.
    Node* dhead = new Node(-1,-1);
    Node* dtail = new Node(-1,-1);

    unordered_map<int, Node*> m;
    int limit;

public:
    LRUCache(int capacity) {
        limit = capacity;
        dhead->next = dtail;
        dtail->prev = dhead;    
    }
    
    int get(int key) {
        if(m.find(key) == m.end()){
            return -1;
        }
        Node* ansaddress = m[key];
        
        m.erase(key);
        deleteNode(ansaddress);
        
        addNode(ansaddress);
        m[key] = ansaddress;

        return ansaddress->val;
    }
    
    void put(int key, int value) {
        //if key alread exist 
        if(m.find(key)!=m.end()){
            deleteNode(m[key]);
            m.erase(key);
        }

        //if capacity reach 
        if(m.size() == limit){
            m.erase(dtail->prev->key);
            deleteNode(dtail->prev);
        }

        Node* newNode = new Node(key,value);
        addNode(newNode);
        m[key] = newNode;
    }

    //Adding a node in DLL
    void addNode(Node* newNode){
        newNode->next = dhead->next;
        dhead->next->prev = newNode;
        newNode->prev = dhead;
        dhead->next = newNode;
    }

    //Deleting a node in DLL
    void deleteNode(Node* trashNode){
        trashNode->prev->next = trashNode->next;
        trashNode->next->prev = trashNode->prev;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */