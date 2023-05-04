#include <iostream>
using namespace std;

// function to heapify the tree
void heapify(int arr[], int n, int root)
{
	int l = 2 * root + 1; //left child index
	int r = 2 * root + 2; //right child index
	int largest; // largest value index

	//check left child
	if (l < n && arr[l] > arr[root]) largest = l;
	else largest = root;

	//check right child
	if (r < n && arr[r] > arr[largest]) largest = r;

	//swapping and call heapify recursively for initial largest node.
	if (largest != root) {
		int temp = arr[root];
		arr[root] = arr[largest];
		arr[largest] = temp;
		heapify(arr, n, largest);

	}
}

// implementing heap sort
void heapSort(int arr[], int n)
{
	int last_index = n - 1;

	//build heap
	for (int i = n/2 ; i > -1; i--) heapify(arr, n, i);

	// extracting elements from heap one by one
	for (int j = n-1; j > -1; j--) {
		int temp = arr[0];
		arr[0] = arr[j];
		arr[j] = temp;
		heapify(arr, last_index, 0);
		last_index--;
	}
}

/* print contents of array */
void displayArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

// main program
int main()
{
	/*int heap_arr[] = {4,17,3,12,9,6};
	int n = sizeof(heap_arr) / sizeof(heap_arr[0]);
	*/
	int n=0;
	//get input array size
	cout << "input array size:";
	cin >> n;

	//create empty array
	int* heap_arr = new int[n];

	//get arry element and store heap_arr
	cout << "Input your array element: ";
	for (int i = 0; i < n; i++) cin >> heap_arr[i];
	//print input array
	cout << "Input array" << endl;
	displayArray(heap_arr, n);

	//sorting
	heapSort(heap_arr, n);

	//print sorted array
	cout << "Sorted array"<<endl;
	displayArray(heap_arr, n);
}