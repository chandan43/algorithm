#include <iostream>
#include <string>
#include <iterator> 
#include <map>
using namespace std;

class DListNode {
public:
    int key;
    string data;
    class DListNode* next;
    class DListNode* prev;
    DListNode(){
        prev = next = this;
    }
    DListNode(int key, string data) {
        this->key = key;
        this->data = data;
        prev = next = this;
    }
};

class DoublyLinkedList {
public:
    DListNode* head;
    int size;
    DoublyLinkedList() {
            head = new DListNode();
            size = 0;
    }
    DListNode* addlist(int key, string data) 
    {
        DListNode* temp = new DListNode(key, data);
        temp->prev = head->prev;
        temp->next = head;
        head->prev->next = temp;
        head->prev = temp;
        size++;
        return temp;
    }
    void display(){
        DListNode* cur = head->next;
        while (cur != head) {
            cout << cur->key << "\t"<< cur->data << "\n";;
            cur = cur->next;
        }
        cout << endl;
    }
    DListNode* removefirst(){
        DListNode* temp = head->next;
        temp->next->prev = head;
        head->next = temp->next;
        --size;
        return temp;    
    }
    void removeAddLast(DListNode* temp){
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        
        temp->prev = head->prev;
        temp->next = head;
        head->prev->next = temp;
        head->prev = temp;
    }
};

class cache {
public:
    DoublyLinkedList* list;
    multimap<int, DListNode*> index;
    int capacity;

    cache(int capacity){
        list = new DoublyLinkedList();
        this->capacity = capacity;
    }

    int isFull()
    {
        return list->size == capacity;
    }

    void put(int key, string data) 
    {
        auto itr = index.find(key);
        if (itr != index.end()) {
               DListNode* p = itr->second;
               p->data = data;
               list->removeAddLast(p);
        }else {
            // new pair
            // is cache full
            if (isFull()) {
                DListNode* temp = list->removefirst();
                index.erase(temp->key);
            }
            DListNode* temp = list->addlist(key, data);
            index.insert({key,temp});
        }
    }
    string get(int key) 
    {
        auto itr = index.find(key);
        DListNode* p = itr->second;
        if (!p)
            return NULL;
        list->removeAddLast(p);
        return p->data;
    }
    void display()
    {
        list->display();
    }

};
int main()
{
    
    cache c(3);
    int i = 0;
    while(++i < 10) {
        c.put(i ,"chandan");
    }
    c.display();
    c.get(8);
    c.display();
}

