//#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct info {
    string name;            //name
    int    tel;             //telephone number
    struct info *pointer;   //pointer of the next data
};

struct info* memalloc(void) {
    return (struct info *)malloc(sizeof(struct info));
};

int main(void) {
    
    struct info *head, *p;
    int node_num = 1;
    head = NULL;
    
    while( p=memalloc(), cin >> p->name >> p->tel ) {
        
        if( p->name == "q" || p->name == "Q") break;
        
        cout << "Current node number : " << node_num << " "
             << "Name : "   << p->name << " "
             << "Tel no. :" << p->tel
             << endl;
        p->pointer = head;
        head = p;
        node_num++;
    }
    
    p = head;
    while( p != NULL ) {
        node_num--;
        cout << "Current node number : " << node_num << " "
             << "Name : "   << p->name << " "
             << "Tel no. :" << p->tel
             << endl;
        p = p->pointer;
    }
    
    
    return 0;
}
