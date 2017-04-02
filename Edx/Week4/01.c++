#ifdef JUDGE
#include <fstream>
std::ifstream cin("input.txt");
std::ofstream cout("output.txt");
#else
#include <iostream>
#endif
#include <vector>
using namespace std;
int n;
vector<int> stack;

bool dfs(auto &matrix, int v, auto &color) {
    color[v] = 1;
    stack.push_back(v);
    cout << v << '\n';
    for (int u = 0; u < n; ++u) {
        if (!matrix[v][u])
            continue;
        if (color[u] == 0 && dfs(matrix, u, color))
            return true;
        if (color[u] == 1)
            return true;
    }
    color[v] = 2;
    stack.pop_back();
    cout << v << '\n';
    return false;
}

void solve(auto &matrix) {
    vector<int> color(n, 0);
    for (int i = 0; i < n; ++i) {
        stack.clear();
        cout << i << endl;
        if (color[i] == 0 && dfs(matrix, i, color)) {
            cout << "YES" << '\n';
            for (auto x: stack)
                cout << x+1 << ' ';
            cout << '\n';
            return;
        }
        cout << endl;
    }
    cout << "NO" << '\n';
}

int main() {
    cin >> n;
    vector< vector<int> > matrix(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        int y, x; cin >> y >> x;
        matrix[y-1][x-1] = 1;
    }

    solve(matrix);

    return 0;
}
