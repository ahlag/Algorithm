#include <iostream>

using namespace std;

void solve(int n,char rodFrom,char middleRod,char rodTo) {

	if(n==1) {
		cout << "Plate 1 from " << rodFrom << " to " << rodTo << endl;
		return;
	}

	solve(n-1,rodFrom,rodTo,middleRod);
	cout << "Plate " << n << " from " << rodFrom << " to " << rodTo << endl;
	solve(n-1,middleRod,rodFrom,rodTo);
}

int main() {

	solve(3,'A','B','C');

	return 0;
}
