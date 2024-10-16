#include <cstddef>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct ListNode{
    long long val;
    ListNode * next;
    ListNode(long long v, ListNode * n = nullptr): val(v), next(n) {}
};

struct ListNode2{
    long long val;
    long long next;
    ListNode2(long long v, long long n = -1): val(v), next(n) {}
};

struct DoubleListNode{
    long long val;
    ListNode * next;
    ListNode * pre;
    DoubleListNode(long long v, ListNode * n = nullptr, ListNode * p = nullptr): val(v), next(n), pre(p) {}
};

void insertElement(ListNode * head, long long p, long long v){
    for(long long i = 0; i < p; ++i){
        head = head -> next;
    }
    // auto n = new ListNode(v);
    // n->next = head->next;
    // head->next = n;
    head->next = new ListNode(v, head->next);
}

void deleteElement(ListNode * head, long long p){
    for(long long i = 0; i < p; ++i){
        head = head->next;
    }
    head->next = head->next->next;
}

void traversal(ListNode * head){
    for(auto i = head->next; i; i = i->next){
        cout << i->val << " ";
    }
}

ListNode * findElement(ListNode * head, long long v){
    while(head->next and head->next->val != v){
        head = head->next;
    }
    return head->next;

}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ListNode * head = new ListNode(0);
    for(int i = 0; i < 5; ++i){
        insertElement(head, 0, 5 - i);
    }

    return 0;
}



