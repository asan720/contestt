
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int answer = 0;

    string line;
    stack<char> skob;
    getline(cin, line, '!');

    for(char ch : line){
        if(ch == '(' || ch == '[' || ch == '{'){
            skob.push(ch);
        }
        if(ch == ')' || ch == ']' || ch == '}'){
            if(skob.empty()){
                answer = 4;
                break;
            }
            char top = skob.top();
            skob.pop();
            if(ch == ')' && top != '(' || ch == ']' && top != '[' || ch == '}' && top != '{'){
                answer = 4;
                break;
            }
        }
    }
    if(!skob.empty()){
        answer = 4;
    }
    if(answer == 4){
        cout<<"NO";
    }else{cout<<"YES";}

}
