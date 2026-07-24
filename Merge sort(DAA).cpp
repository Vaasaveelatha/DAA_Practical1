#include<iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high)
{
    int temp[50];
    int i = low, j = mid + 1, k = low;

    while(i <= mid && j <= high)
    {
        if(arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while(i <= mid)
        temp[k++] = arr[i++];

    while(j <= high)
        temp[k++] = arr[j++];

    for(i = low; i <= high; i++)
        arr[i] = temp[i];
}

void mergeSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int mid = (low + high) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

int main()
{
    int arr[50], n, i;

    cout << "Enter the Size: ";
    cin >> n;

    cout << "Enter " << n << " Numbers: ";
    for(i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\nSorting the Array using Merge Sort Technique..\n";

    mergeSort(arr, 0, n - 1);

    cout << "\nArray Sorted Successfully!\n";
    cout << "\nThe New Array is:\n";

    for(i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;

    return 0;
}
