#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

int main()
{
    cout<<"Enter the number of inputs: ";
    int N;
    cin>>N;
    int arr[N];
    for(int i=0;i<N;i++){
        arr[i]=rand()*1000;
    }
    cout<<"Array before sorting: ";
    for(int i=0;i<N;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    clock_t t_start = clock(); 
	insertionSort(arr, N);
    double time = (double)(clock()-t_start)/CLOCKS_PER_SEC;
    cout<<"Array after sorting: ";
	for (int i = 0; i < N; i++)
		cout << arr[i] << " ";
    cout<<endl;
    cout<<"The time taken to run is: "<<time;
	return 0;
}
