#include <iostream>

using namespace std;

int binarySearch(int nums[],int low,int high,int num) {

	//recursive implementation - we need a base case
	if(low>high) return -1;

	//pick the middle item (middle index)
	int middle = low + (high-low)/2;

	//if the middle item is the number we are looking for: we're done!!!
	if(nums[middle]==num) return middle;

	//check the left sub-array recursively
	if(num<nums[middle]) {
		return binarySearch(nums, low, middle-1, num);
	//check right sub-array recursively
	} else {
		return binarySearch(nums, middle+1, high, num);
	}
}

int main() {

	//the array in which we search
	int nums[] = {1,2,3,4,5,10,15,20,30,40,50,60,70};
	//the number we are looking for
	int num = 60;
	//the size of the array
	int n = sizeof(nums)/sizeof(nums[0]);

	cout << "Index of number " << num << " is: " << binarySearch(nums, 0, n-1, num) << endl;

	return 0;
}
