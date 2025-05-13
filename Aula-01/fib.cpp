//
// Created by IFPE on 07/05/2025.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int fib(int n) {
//    cout << n << " ";
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib(n - 1) + fib (n - 2);
}

int fib2(int n) {
    vector<int> f(n + 1);
    f[0] = 0;
    f[1] = 1;

    for (int i = 2; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }

    return f[n];
}

string maiscula(string str) {
    int dif = 'A' - 'a';

    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = (char)str[i] + dif;
        }
    }

    return str;
}

void maisculaCPP(string& str) {
    int dif = 'A' - 'a';
    for (char &c : str) {
        if (c >= 'a' && c <= 'z') {
            c = (char)c + dif;
        }
    }
}

int main () {
    string aula = "tads";

//    aula = maiscula(aula);
//    maisculaCPP(aula);

//    std::transform(aula.begin(), aula.end(), aula.begin(), ::toupper);

    cout << aula << endl;

//    cout << fib2(40) << endl;
//    cout << fib(40) << endl;

        vector<int> A(10, 0);

//        vector<vector<int>> M (10, vector<int>(5, -1));
        vector<vector<int>> M (10);


}