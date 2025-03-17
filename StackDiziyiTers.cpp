#include <iostream> 
#include <stack>    

using namespace std; 


void reverseArray(int arr[], int size) {
    stack<int> s; 

    
    for (int i = 0; i < size; ++i) {
        s.push(arr[i]); 
    }

   
    for (int i = 0; i < size; ++i) {
        arr[i] = s.top(); 
        s.pop();          
    }
}

int main() {
    int arr[100]; 
    int size;     

  
    cout << "Enter the size of the array: ";
    cin >> size;

   
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i]; 
    }

   
    reverseArray(arr, size);

   
    cout << "Reversed array: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " "; 
    }
    cout << endl;

    return 0; 
}
