#include <iostream>

using namespace std;

typedef unsigned long long ull;

int main() {
    ull a, b, n;
    ull soma = 0;

    std::cin >> a; // scanf("%d", &a);
    std::cin >> b;

//    for (unsigned long long i = a; i <= b; i++) {
//        soma += i;
//    }

    n = b - a + 1;
    soma = n * (a + b) / 2;

    cout << soma << endl;

    return 0;
}
