#include <iostream>
#include <math.h> 

using namespace std;

void debai(int* n) {
    int sqrtN = static_cast<int>(sqrt(*n));  
    if (sqrtN * sqrtN == *n) {  
        cout << "So " << *n << " la so chinh phuong." << endl;
    }
    else {
        cout << "So " << *n << " khong la so chinh phuong." << endl;
    }
}

int main() {
    int n;
    cout << "Moi ban nhap so nguyen n: ";
    cin >> n;

  debai(&n); 
    return 0;
}
