#include <iostream>

using namespace std;

typedef unsigned long long ull;

struct Obj {
    int x = 2;
    int y = 3;
};

void func2(Obj ooo) {
    int v = ooo.y;
    ooo.x = v * 2;
}

void func1(int p, Obj oo) {
    int k = p;
    if (p == 0) {
        return;
    }
    func1(p - 1, oo);
}

int main() {
    int i = 5;  Obj o1;
    func1(i, o1);

//    ull a, b, n;
//    ull soma = 0;
//
//    std::cin >> a; // scanf("%d", &a);
//    std::cin >> b;

//    for (unsigned long long i = a; i <= b; i++) {
//        soma += i;
//    }

//    n = b - a + 1;
//    soma = n * (a + b) / 2;
//
//    cout << soma << endl;

    return 0;
}
