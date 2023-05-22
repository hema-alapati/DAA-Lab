#include <bits/stdc++.h>
#include <ctime>
using namespace std;

void insertionSort(vector<int> &arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    vector<int> v = {5, 4, 3, 2, 1};
    int n = v.size();
    clock_t start = clock();
    insertionSort(v, n);
    clock_t end = clock();
    double timeForExec = (double)(end - start) / CLOCKS_PER_SEC;
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << "Time: " << timeForExec;
    return 0;
}
