
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int firstcol;
    int secondcol;
    int fir;
    int sec;
    vector<int> allnumbers;
    vector<int> firstnumbers;
    vector<int> secondnumbers;
    cin >> firstcol;
    for (int i = 0; i < firstcol; i++) {
        cin >> fir;

        firstnumbers.push_back(fir);
    }
    cin >> secondcol;
    for (int i = 0; i < secondcol; i++) {
        cin >> sec;

        secondnumbers.push_back(sec);
    }
    for (int i = 0; i < firstcol; i++) {
        secondnumbers.push_back(firstnumbers[i]);
    }
    cout<<endl;

    cout<<endl;
    sort(secondnumbers.begin(), secondnumbers.end());
    for (int i = 0; i < secondcol + firstcol; i++) {
        cout << secondnumbers[i];
        cout << " ";


    }

}
