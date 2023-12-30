
#include <iostream>
#include <map>
#include <string>


using namespace std;

int main() {
    int nums, nums2;
    string word;
    map<string, int> karta;

    cin >> nums;
    

    for (int i = 0; i < nums; i++) {
        string login;
        int schet;

        getline(cin, login, ';');
        cin>>schet;

        login.replace(0, 1, "");
        karta[login] = schet;
    }
    cin >> nums2;
    for (int i = 0; i < nums2; i++) {
        string line2;
        cin >> line2;
        cout << karta[line2] << ' ';

    }
    

  

}
