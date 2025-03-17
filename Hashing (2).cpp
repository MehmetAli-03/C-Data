#include<iostream>
#define TABLE_SIZE 10
#define PRIME 7
using namespace std;

int h[TABLE_SIZE]={};
// double hashing
void insert()
{
    int key,index,hkey1,hkey2;
    cout<<"Enter the value in the array"<<endl;
    cin>>key;
    hkey1=key%TABLE_SIZE;
    hkey2=PRIME - (key % PRIME);
   for (int i = 0; i < TABLE_SIZE; i++) {
        index = (hkey1 + i * hkey2) % TABLE_SIZE;

        if (h[index] == 0) {
            h[index] = key;
            return;
        }
    }
    cout << "\nTable is full!!";
}
void search()
{
    int key,index,hkey1,hkey2;
    cout<<"which one search the number"<<endl;
    cin>>key;
    hkey1=key%TABLE_SIZE;
    hkey2=PRIME - (key % PRIME);
     for (int i = 0; i < TABLE_SIZE; i++) {
        index = (hkey1 + i * hkey2) % TABLE_SIZE;

        if (h[index] == key) {
            cout << "Value " << index << " is here ";
            return;
        } else if (h[index] == 0) {
            break;
        }
    }
    cout << "\n didn't search key!\n";
}
void display()
{
    cout << "\nElements in the hash table are:\n";
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        cout << "At index " << i << "\t value = " << h[i] << endl;
    }
}

int main() {
    int opt;
    while (true) {
        cout << "\n1 insert  2. Display  3. Search  4. Exit\n";
        cin >> opt;

        switch (opt) {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4:
                exit(0);

        }
    }
    return 0;
}
