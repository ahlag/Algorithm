#include "Stack.h"
#include <string>
#include <iostream>
using std::string;
using std::cout;

int main()
{
	Stack<int> stack;

	stack.push(10);
	stack.push(3);

	cout << stack.size() << '\n';

	cout << stack.pop() << '\n';

	cout << stack.size() << '\n';

	cout << stack.pop() << '\n';

	return 0;
}
