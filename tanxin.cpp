#include <iostream>
using namespace std;

void sort(int m[], int n) {
    int i, j, t;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (m[j] > m[j + 1]) {
                t = m[j + 1];
                m[j + 1] = m[j];
                m[j] = t;
            }
        }
    }
}

void comp(int m[], int n, int r) {
    for (int i = r; i < n; i++) {
        m[i] = m[i] + m[i - r];
    }
}

int sum(int a[], int n) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += a[i];
    }
    return s;
}

int main() {
    int r, n;
    int a[510] = { 0 };
    cout << "水龙头，人:\n";
    cin >> r >> n;

    // 输入检查
    if (r <= 0 || n <= 0 || n > 510) {
        cout << "输入无效，请检查输入的值。\n";
        return 1;
    }

    cout << "时间:";
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, n);
    comp(a, n, r);
    int s = sum(a, n);
    cout << "结果: " << s << endl;

    // 调试信息
    cout << "排序后的数组: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}