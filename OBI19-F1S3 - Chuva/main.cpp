#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

bool checa_chuva(const vector<vector<char>> &C, int i, int j) {
    return (i > 0 && C[i - 1][j] == 'o') ||
    (j > 0 && i < C.size() - 1 && C[i][j - 1] == 'o' && C[i + 1][j - 1] == '#') ||
    (j < C[i].size() - 1 && i < C.size() - 1 && C[i][j + 1] == 'o' && C[i + 1][j + 1] == '#');
}

void solucao_iterativa(vector<vector<char>> &C) {
    bool change;
    do {
        change = false;
        for (int i = 0; i < C.size(); i++) {
            for (int j = 0; j < C[i].size(); j++) {
                if (C[i][j] != '.') continue;

                if (checa_chuva(C, i, j)) {
                    C[i][j] = 'o';
                    change = true;
                }
            }
        }
    }
    while (change);
}

bool valida(const vector<vector<char>> &C, int i, int j) {
    return (i >= 0 && j >= 0 && i < C.size() && j < C[i].size()
            && C[i][j] == '.');
}

void chuva(vector<vector<char>> &C, int i, int j) {
    if (C[i][j] == 'o' || checa_chuva(C, i, j)) {

        C[i][j] = 'o';

        if (valida(C, i, j - 1)) chuva(C, i, j - 1);
        if (valida(C, i, j + 1)) chuva(C, i, j  + 1);
        if (valida(C, i + 1, j)) chuva(C, i + 1, j);
    }
}

void solucao_recursiva(vector<vector<char>> &C, int x, int y) {
    chuva(C, x, y);
}

void solucao_pilha(vector<vector<char>> &C, int x, int y) {
    stack<pair<int, int>> pilha;

    pilha.emplace(x, y);

    while (!pilha.empty()) {
        auto [i, j] = pilha.top();
        pilha.pop();

        if (C[i][j] == 'o' || checa_chuva(C, i, j)) {

            C[i][j] = 'o';

            if (valida(C, i + 1, j)) pilha.emplace(i + 1, j);
            if (valida(C, i, j - 1)) pilha.emplace(i, j - 1);
            if (valida(C, i, j + 1)) pilha.emplace(i, j + 1);
        }
    }
}

void solucao_fila(vector<vector<char>> &C, int x, int y) {
    queue<pair<int, int>> fila;

    fila.emplace(x, y);

    while (!fila.empty()) {
        auto [i, j] = fila.front();
        fila.pop();

        if (C[i][j] == 'o' || checa_chuva(C, i, j)) {

            C[i][j] = 'o';

            if (valida(C, i + 1, j)) fila.emplace(i + 1, j);
            if (valida(C, i, j - 1)) fila.emplace(i, j - 1);
            if (valida(C, i, j + 1)) fila.emplace(i, j + 1);
        }
    }
}

int main() {
    int n, m, x, y;

    cin >> n >> m;

    vector<vector<char>> C(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> C[i][j];
            // Encontrando posição inicial
            if (C[i][j] == 'o') {
                x = i;
                y = j;
            }
        }
    }

//    solucao_iterativa(C);

//    solucao_recursiva(C, x, y);

//    solucao_pilha(C, x, y);

    solucao_fila(C, x, y);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << C[i][j];
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}


