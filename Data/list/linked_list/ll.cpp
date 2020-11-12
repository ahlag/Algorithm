#include <iostream>

using namespace std;

struct node {
    string name;
    string tel;
    struct node *next;
};

struct node *talloc(void) {
    return (struct node *)malloc(sizeof(struct node));
};

int main() {
    
    struct node *head, *p, *old;
    int node_num = 1;
    head = talloc();
    
    cin >> head->name >> head->tel;
    old = head;
    
    cout << "Current node number : " << node_num << " "
         << "Name : "   << p->name << " "
         << "Tel no. :" << p->tel
         << endl;
    
    while(p=talloc(), cin >> p->name >> p->tel) {
        
        if( p->name == "q" || p->name == "Q") break;
        
        cout << "Current node number : " << node_num << " "
            << "Name : "   << p->name << " "
            << "Tel no. :" << p->tel
            << endl;
        
        old->next = p;
        old = p;
        node_num++;
    }
    old->next = NULL;
    
    cout << "yes " << endl;
    p = head;
    
    while(p != NULL) {
        node_num--;
        cout << "Current node number : " << node_num << " "
        << "Name : "   << p->name << " "
        << "Tel no. :" << p->tel
        << endl;
        p = p->next;
    }
    
    return 0;
    
}
