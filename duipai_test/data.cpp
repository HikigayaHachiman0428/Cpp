#include <iostream>
#include<cstdlib>
#include<ctime>
int main() {
    freopen("test.in","w",stdout);
    srand(time(0));
    int upper = 1e7; int lower = 1e5;
    std::cout << (rand() % (upper - lower + 1)) + lower << std::endl;
    return 0;
}