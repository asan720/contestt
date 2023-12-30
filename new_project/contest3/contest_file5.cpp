
#include "iostream"
#include <cmath>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

int main() {
int n;
string wordss;

map<string, int> words;
cin>>n;

for (int i = 0; i < n; i++) {

string word;
cin >> word;
auto iterator = words.find(word);
if (iterator != words.end()) {
iterator->second += 1;

}
else {
words.insert(make_pair(word, 1));
}
}
int maxcount = 1;
    for (const auto& [word, sim] : words){
        if (sim > maxcount){
            maxcount = sim;
        }
    }
    
for (const auto& [word, sim] : words){
        if(sim == maxcount){
            cout<<word<<" ";
        }

    }


}
