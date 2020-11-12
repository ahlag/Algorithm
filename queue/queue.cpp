#include <iostream>
#define LEN 100005

using namespace std;

typedef struct pp {
    char name[10];
    int t;
} Queue;

Queue Q[LEN];
int head, tail;

void enqueue(Queue x) {
    Q[tail] = x;
    tail = (tail + 1) % LEN;
}

Queue deque() {
    Queue tmp = Q[head];
    head = (head + 1) % LEN;
    return tmp;
}

int main() {

    int quantum, n;
    int cur_time, elaps = 0;
    Queue cur;
    
    cin >> n >> quantum;

    for( int i = 1; i <= n; i++ ) {
        cin >> Q[i].name >> Q[i].t;
    }

    head = 1; tail = n + 1;

    while ( head != tail ) {
        cur = deque();
        cur_time = min(cur.t,quantum);
        cur.t -= cur_time;
        elaps += cur_time;
        if (cur.t > 0) {
            enqueue(cur);
        } else {
            cout << cur.name << " " <<  elaps << endl;
        }
    }

    return 0;
}