#include <iostream>
using namespace std;
//[0,1,0], 3 , 0
bool myFunction(int array[], const unsigned int size, int toCheck) { //zad 6
    if (size==2 || size==1) {
        return (array[0] == toCheck);
    } else {
        bool is_ok = false;
        if ((size-1)%2==0) {
            is_ok = (array[size-1]==toCheck); //size nieparzysty
        } else {
            is_ok = (array[size-2]==toCheck); //size parzysty
        }
        if (!is_ok)
            return false;
        else
            return myFunction(array, size-2, toCheck);
    }
}

bool myFunction3(int tab[], const unsigned int size, int toCheck){ //zad 7
    int n = size - 1;
    if(n == -1) {
        if (toCheck > 0) {
            return true;
        } else {
            return false;
        }
    }
    else {
        return myFunction(tab, n, toCheck - tab[n]);
    }
}

bool myFunction2(int array[], const unsigned int size, int toCheck) {
    if (size==1) {
        return (toCheck - array[size-1] > 0);

    } else {
        bool is_ok = (toCheck - array[size-1] > 0);
        if (!is_ok) {
            return false;
        } else {
            return is_ok && myFunction2(array, size-1, toCheck - array[size-1]);
        }
    }
}


int main() {

    int array[11]={0,1,0,1,0,1,0,1,0,9,0};

    cout<<myFunction(array, 11, 0);
    cout<<"\n";
    cout<<myFunction2(array, 11, 0);
    return 0;
}
