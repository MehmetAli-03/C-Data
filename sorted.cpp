#include<iostream>
using namespace std;
void shortedSelection(int arr[], int size)
{
    cout << "Using Selection Sort" << endl;
    for (int i = 0; i < size; i++)
    {
        int minNum = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minNum])
            {
                minNum = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minNum];
        arr[minNum] = temp;
    }
}
void shortedInsertion(int arr[], int size)
{
    cout << "Using Insertion Sort" << endl;
    int temp, j;
    for (int i = 0; i < size; i++)
    {
        temp = arr[i];
        j = i - 1;
        while ((j >= 0) && (arr[j] > temp)) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
    }
}

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main()
{
    int size;
    cout << "Enter the size of array: ";
    cin >> size;
    cout << "Enter the items of the array: ";

    int* arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << endl;
    cout << "Size of Array: " << size << endl;
    cout << "Unsorted array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;


    if (size < 5) {
        shortedSelection(arr, size);
    }
    else if (size >= 5 && size <= 8) {
        shortedInsertion(arr, size);
    }
    else if(size>=9){
        cout << "Using Merge Sort" << endl;
        mergeSort(arr, 0, size - 1);
    }

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}
