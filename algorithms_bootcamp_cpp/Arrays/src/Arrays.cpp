
#include <iostream>
using namespace std;

int main() {

	const int SIZE = 10;

	//this is how we can create an array for 10 integers (size can not be changed later)
	int nums[SIZE] = {1,2,3,4,5,6,7,8,9,10};

	//we can access items with indexes in O(1) (this is exactly why we like arrays)
	cout << nums[2] << "\n";

	//if we want to update and know the index: we can do it in O(1) again
	nums[2] = 100;
	cout << nums[2] << "\n";

	//if we DO NOT know the index of the item we are looking for: we have to consider all the items
	//one by one (this is called linear search with O(N) linear running time)
	for(int i=0;i<SIZE-1;i++) {
		if(nums[i] == 8)
			cout << "Index of the item we are looking for is " << i << "\n";
	}

	//REMOVE A GIVEN ITEM FROM THE ARRAY

	//OK we can remove it but there is a "hole" in the data structure so we have to shift all items
	nums[2] = 0;

	//this is why this operation has O(N) running time
	for(int i=2;i<SIZE-1;i++)
		nums[i] = nums[i+1];

	nums[SIZE-1] = 0;

	//show the items
	for(int i=0;i<SIZE-1;i++)
		cout << nums[i] << "\n";

	return 0;
}
