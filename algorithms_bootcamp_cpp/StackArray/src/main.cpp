#include "Stack.h"
#include <string>
#include <iostream>
using std::string;
using std::cout;

int main()
{
	Stack<string> stack;

	stack.push("Adam");
	stack.push("Joe");

	cout << stack.size() << '\n';

	cout << stack.pop() << '\n';

	cout << stack.size() << '\n';

	cout << stack.pop() << '\n';

	return 0;
}
