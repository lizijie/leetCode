#include <stdio.h>
#include <stdlib.h>

#define MOD 10

struct Node {
    int value;
    struct Node *pre;
    struct Node *next;
};

typedef struct {
    struct Node** bucket;
} MyHashSet;

/** Initialize your data structure here. */
MyHashSet* myHashSetCreate() {
    MyHashSet* set = (MyHashSet*)malloc(sizeof(MyHashSet));
    set->bucket = (struct Node**)malloc(MOD * sizeof(struct Node*));

    for (int i = 0; i < MOD; ++i)
    {
        set->bucket[i] = NULL;
    }

    return set;
}

void myHashSetAdd(MyHashSet* obj, int key) {
    int index = key % MOD;
    struct Node* head = obj->bucket[index];

    struct Node* itr = head;
    while (itr != NULL && itr->value != key && itr->next != NULL)
    {
        itr = itr->next;
    }

    if (head == NULL || (itr != NULL && itr->value != key))
    {
        struct Node* node = (struct Node*)malloc(sizeof(struct Node));
        node->next = NULL;
        node->pre = NULL;

        node->value = key;
        node->next = head;

        if (head != NULL)
        {
            head->pre = node;
        }

        obj->bucket[index] = node;
    }
}

void myHashSetRemove(MyHashSet* obj, int key) {
    int index = key % MOD;
    struct Node* head = obj->bucket[index];

    struct Node* itr = head;
    while (itr != NULL && itr->value != key && itr->next != NULL)
    {
        itr = itr->next;
    }

    if (itr != NULL && itr->value == key)
    {
        struct Node* pre = itr->pre;
        struct Node* next = itr->next;

        // set next
        if (pre != NULL)
        {
            pre->next = next;
        }

        if (next != NULL)
        {
            next->pre = pre;
        }

        // reset head
        if (itr == head)
        {
            obj->bucket[index] = next;
        }

        free(itr);
        
        itr = NULL;
    }   
}

/** Returns true if this set contains the specified element */
bool myHashSetContains(MyHashSet* obj, int key) {
    int index = key % MOD;
    struct Node* head = obj->bucket[index];

    struct Node* itr = head;
    while (itr != NULL)
    {
        if (itr->value == key)
        {
            break;
        }

        itr = itr->next;
    }

    return itr != NULL && itr->value == key;
}

void myHashSetFree(MyHashSet* obj) {
    for (int i = 0; i < MOD; ++i)
    {
        struct Node* head = obj->bucket[i];
        struct Node* itr = head;
        while (itr != NULL)
        {
            struct Node* temp = itr->next;
            free(itr);
            itr = temp;   
        }
    }

    free(obj->bucket);
}

int main()
{
    // Your MyHashSet struct will be instantiated and called as such:
    //

    MyHashSet* obj = myHashSetCreate();
    myHashSetAdd(obj, 6);
    myHashSetRemove(obj, 4);
    myHashSetAdd(obj, 17);
    printf("%d\n", myHashSetContains(obj, 14));
    myHashSetAdd(obj, 14);

    myHashSetRemove(obj, 17);
    myHashSetAdd(obj, 14);
    myHashSetAdd(obj, 14);
    myHashSetAdd(obj, 18);
    myHashSetAdd(obj, 14);
    myHashSetFree(obj);

    /*
    printf("%d\n", myHashSetContains(obj, 11));
    myHashSetAdd(obj, 2);
    printf("%d\n", myHashSetContains(obj, 1));
    printf("%d\n", myHashSetContains(obj, 3));
    myHashSetAdd(obj, 2);
    printf("%d\n", myHashSetContains(obj, 2));
    myHashSetRemove(obj, 2);
    printf("%d\n", myHashSetContains(obj, 2));
    myHashSetFree(obj);
    */
    return 0;
}


