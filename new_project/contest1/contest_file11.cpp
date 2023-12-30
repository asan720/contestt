
#include <iostream>
#include <math.h>
using namespace std;

int main (){
    int a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;
    int y = abs(a - b);
    int i = abs(a - c);
    if (y>i){
        cout << "C " << i;
    }
    else{
        cout << "B "<< y;
    }
}
