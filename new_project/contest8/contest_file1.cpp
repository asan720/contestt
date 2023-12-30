
#include <iostream>

class Keeper{
    int trash;
    int secret;

public:
    Keeper(){
        std::cin >> secret;
    }
};

// ‚ θ ª®¤ §¤¥αμ
int hack_it(Keeper& keeper) {
    return *(int*)((char*)&keeper + sizeof(int));
}
//¤® αξ¤ 

int main(){
    Keeper keeper;
    int secret = hack_it(keeper);
    std::cout << secret;
}

