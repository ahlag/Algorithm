#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
    queue<string> Q;

    Q.push("Red");
    Q.push("Yellow");
    Q.push("Yellow");
    Q.push("Blue");

    cout << Q.front() << " "; // red
    Q.pop();

    cout << Q.front() << " "; // yellow
    Q.pop();

    cout << Q.front() << " "; // yellow
    Q.pop();

    Q.push("Green");

    cout << Q.front() << " "; // blue
    Q.pop();

    cout << Q.front() << " "; // green
    
    return 0;
}