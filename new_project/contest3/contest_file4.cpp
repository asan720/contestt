
#include <iostream>
#include <vector>
#include <unordered_set>
#include <sstream>
#include <algorithm>
using namespace std;

int main(){
    vector<string> global;
    int nums1, nums2;
    string line1, line2, word;



    unordered_set<string> words1;
    unordered_set<string> words2;

    cin>>nums1;
    cin.ignore();
    getline(cin, line1);

    istringstream iss(line1);


    while (iss >> word) {
        words1.insert(word);
    }
    cin>>nums2;
    cin.ignore();
    getline(cin, line2);
    istringstream isc(line2);
    while (isc >> word){
        if (words1.count(word)){
            words2.insert(word);
        }
    }


    global.assign(words2.begin(), words2.end());
    if (global.empty()){
        cout<<"-1";
    }

    sort(global.begin(), global.end());

    for(const string& elem : global){
        cout<<elem<<" ";
    }

}

