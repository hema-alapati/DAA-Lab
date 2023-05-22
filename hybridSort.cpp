#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &arr, int low, int high)
{
    int i, key, j;
    for (i = low; i < high; i++)
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

void merge(vector<int> &v, int low, int mid, int high)
{
    vector<int> temp;
    int i = low;
    int j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (v[i] < v[j])
        {
            temp.push_back(v[i]);
            i++;
        }
        else
        {
            temp.push_back(v[j]);
            j++;
        }
    }
    while (i <= mid)
    {
        temp.push_back(v[i]);
        i++;
    }
    while (j <= high)
    {
        temp.push_back(v[j]);
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        v[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &v, int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        mergeSort(v, low, mid);
        mergeSort(v, mid + 1, high);
        merge(v, low, mid, high);
    }
}

void mergeInsertion(vector<int> &arr, int l, int r, int k)
{
    if (l < r)
    {
        if (r - l + 1 <= k)
        {
            insertionSort(arr, l, r + 1);
        }
        else
        {
            int m = l + (r - l) / 2;
            mergeInsertion(arr, l, m, k);
            mergeInsertion(arr, m + 1, r, k);
            merge(arr, l, m, r);
        }
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr;
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    cout << "Enter the threshold: ";
    int k;
    cin >> k;
    mergeInsertion(arr, 0, n - 1, k);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
