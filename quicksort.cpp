#include<iostream>
using namespace std;

int divide(int arr[],int start,int end)
{
    int pivot=arr[end];
    int index=start;
    for(int i=start; i<end; i++)
    {
        if(arr[i]<pivot)
        {
            int temp=arr[i];
            arr[i]=arr[index];
            arr[index]=temp;
            index++;
        }
    }
    int temp=arr[end];
    arr[end]=arr[index];
    arr[index]=temp;

    return index;
}

void  quickSort(int arr[],int start, int end)
{
    if(start<end)
    {
        int d=divide(arr,start,end);
        quickSort(arr,start,(d-1));
        quickSort(arr,(d+1),end);
    }
}
int main() {
    int size;
    cout << "Enter the size of array: ";
    cin >> size;

    int* arr = new int[size];

    cout << "Enter the items of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "\nUnsorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    quickSort(arr, 0, size - 1);

    cout << "\nSorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;


    delete[] arr;

    return 0;
}
