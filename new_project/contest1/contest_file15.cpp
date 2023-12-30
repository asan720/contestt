
#include <iostream>
#include <math.h>
using namespace std;

int main(){
    string line;
    string simbol;
    int schet = 1;
    string simbols;
    cin>>line;
    line += ";";
    for (int i = 0; i<line.length()-1; i++){
        
        if (line[i] == line[i+1]){
            schet++;
            
            
        }
        if (line[i] != line[i+1]){
            cout<<line[i];
            if (schet>1){
                cout<<schet;
                schet = 1;
            }
        }
        
    }
}
