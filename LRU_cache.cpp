/*
LRU Cache (Least Recently Used)
*/

#include <iostream>
#include <unordered_map>
using namespace std;

class DoubleLinkedList
{
public:
    int key, value;
    DoubleLinkedList *next;
    DoubleLinkedList *prev;

    DoubleLinkedList(int key, int value)
    {
        this->key = key;
        this->value = value;
    }
};

class LRU
{

    DoubleLinkedList *head = new DoubleLinkedList(0, 0);
    DoubleLinkedList *tail = new DoubleLinkedList(0, 0);

    int capacity;
    unordered_map<int, DoubleLinkedList*> hashmap;

public:
    LRU(int capacity)
    {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void put(int key, int value)
    {
        if (hashmap.size() < capacity)
        {
            // size less than capacity just insert after head;
            if (hashmap.find(key) != hashmap.end())
            {
                // key exist already than delete previous one and insert new one after head

                // 1.deleting previous key-value
                DoubleLinkedList *todlt = hashmap[key];
                todlt->prev->next = todlt->next;
                todlt->next->prev = todlt->prev;

                delete todlt;
            }

            // Inserting newNode
            DoubleLinkedList *current= new DoubleLinkedList(key, value);
            current->next = head->next;
            head->next->prev = current;
            head->next = current;
            current->prev = head;

            hashmap[key] = current;
        }
        else
        {
            if (hashmap.find(key) == hashmap.end())
            {
                // 1. dlt previous to tail i.e. least recently used
                DoubleLinkedList *todlt = tail->prev;
                todlt->prev->next = todlt->next;
                todlt->next->prev = todlt->prev;

                delete todlt;
            }
            else
            {
                // 1.deleting previous key-value
                DoubleLinkedList *todlt = hashmap[key];
                todlt->prev->next = todlt->next;
                todlt->next->prev = todlt->prev;

                delete todlt;
            }
            // Inserting newNode
            DoubleLinkedList *current= new DoubleLinkedList(key, value);
            current->next = head->next;
            head->next->prev = current;
            head->next = current;
            current->prev = head;

            hashmap[key] = current;
        }
    }

    int get(int key)
    {
        // Check in hashmap if exist
        if (hashmap.find(key) != hashmap.end())
        {
            // 1. get its value
            DoubleLinkedList *ans = hashmap[key];
            int value = ans->value;

            // 2. make it last recently used i.e. dlt and insert it next to head;
            //  1.deleting key-value
            ans->prev->next = ans->next;
            ans->next->prev = ans->prev;

            delete ans;

            //  2. Inserting same Node
            DoubleLinkedList *current= new DoubleLinkedList(key, value);
            current->next = head->next;
            head->next->prev = current;
            head->next = current;
            current->prev = head;

            hashmap[key] = current;

            return value;
        }
        else
        {
            return -1;
        }
    }

    void printLRUCache(){
        DoubleLinkedList* temp = head;

        while(temp!= NULL){
            cout<<"("<<temp->key<<", "<<temp->value<<") <-> ";
            temp=temp->next;
        }
        cout<<"NULL";
    }
};

int main()
{
    LRU* lrucache = new LRU(3);
    lrucache->put(1, 10);
    lrucache->put(3,15);
    lrucache->put(2,12);
    cout<<"\nget(3)->"<<lrucache->get(3);
    lrucache->put(4,20);
    cout<<"\nget(2)->"<<lrucache->get(2);
    lrucache->put(4,25);
    cout<<endl;
    lrucache->printLRUCache();
    return 0;
}
