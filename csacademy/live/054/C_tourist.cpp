/**
 *        author:    tourist
 *        created: 25.10.2017 11:46:41
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    multiset<int> s;
    for (int i = 0; i < k && i < n; i++) {
        s.insert(a[i]);
    }
    for (int i = 0; i < n; i++) {
        if (i + k < n) {
            s.insert(a[i + k]);
        }
        int x = *(s.begin());
        if (x < a[i]) {
            for (int j = i + k; j >= i + 1; j--) {
                if (j < n && a[j] == x) {
                    swap(a[i], a[j]);
                    break;
                }
            }
            break;
        }
        s.erase(s.find(a[i]));
    }
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            putchar(' ');
        }
        printf("%d", a[i]);
    }
    printf("\n");
    return 0;
}
