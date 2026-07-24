#include<iostream>
using namespace std;

void quicksort(int a[], int low, int high)
{
    int i, j, pivot, temp;

    if(low < high)
    {
        pivot = low;
        i = low;
        j = high;

        while(i < j)
        {
            while(a[i] <= a[pivot] && i < high)
                i++;

            while(a[j] > a[pivot])
                j--;

            if(i < j)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }

        temp = a[pivot];
        a[pivot] = a[j];
        a[j] = temp;

        quicksort(a, low, j - 1);
        quicksort(a, j + 1, high);
    }
}

int main()
{
    int a[50], n, i;

    cout << "Enter the Size: ";
    cin >> n;

    cout << "Enter " << n << " Numbers: ";
    for(i = 0; i < n; i++)
        cin >> a[i];

    quicksort(a, 0, n - 1);

    cout << "\nSorted Array:\n";

    for(i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}


