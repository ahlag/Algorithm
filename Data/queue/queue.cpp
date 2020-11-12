#include <iostream>

using namespace std;

const int MaxSize = 100;
int queue[MaxSize];
int head = 0, tail = 0;
int queuein(int);
int queueout(int *);
void disp(void);

int main(void) {
    char c;
    int n;
    
    while(cin >> c) {
        switch(c) {
            case 'i':
            case 'I':   cout << "Please type a number -> "; cin >> n;
                        if( queuein(n) == -1 ) {
                        cout << "The queue is full!" << endl;
                        }
                        break;
            case 'o':
            case 'O':   if(queueout(&n) == -1) {
                            cout << "The queue is empty" << endl;
                        } else {
                            cout << "Queue data :" << n << endl;
                        }
                        break;
            case 'l':
            case 'L':   disp();
                        break;
        }
    }
    return 0;
}

int queuein(int n) {
    if( (tail+1)%MaxSize != head ) {
        queue[tail] = n;
        tail++;
        tail = tail%MaxSize;
        return 0;
    } else {
        return -1;
    }
}

int queueout(int *n) {
    if(head != tail) {
        *n = queue[head];
        head++;
        head = head%MaxSize;
        return 0;
    } else {
        return -1;
    }
}

void disp(void) {
    int i;
    i = head;
    while(i != tail) {
        cout << "queue[" << i << "] = " << queue[i] << endl;
        i++;
        i=i%MaxSize;
    }
}
