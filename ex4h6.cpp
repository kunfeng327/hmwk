#include <iostream>
#include <cstring>
using namespace std;


class bign {
private:
    int len; // 有效长度
    int num[500]; // 存储大整数
public:
    bign() {
        len = 0;
        memset(num, 0, sizeof(num));
    }
    bign(int x) {
        len = 0;
        memset(num, 0, sizeof(num));
        do {
            num[len++] = x % 10;
            x /= 10;
        } while (x > 0);
    }
    bign operator=(const char *s) {
        len = strlen(s);
        memset(num, 0, sizeof(num));
        for (int i = 0; i < len; i++) {
            num[i] = s[len - 1 - i] - '0';
        }
        return *this;
    }
    bign operator+(const bign &b) const;
    bign operator-(const bign &b) const;
    bign operator*(const bign &b) const;
    bign operator/(const bign &b) const;
    bign operator+=(const bign &b) {
        *this = *this + b;
        return *this;
    }
    bign operator+=(int x) {
        *this = *this + bign(x);
        return *this;
    }
    bool operator<(const bign &b) const;
    bool operator>(const bign &b) const;
    bool operator<=(const bign &b) const;
    bool operator>=(const bign &b) const;
    bool operator==(const bign &b) const;
    bool operator!=(const bign &b) const;
    friend istream &operator>>(istream &in, bign &a);
    friend ostream &operator<<(ostream &out, const bign &a);
};

bign bign::operator+(const bign &b) const {
    bign c;
    c.len = max(len, b.len);
    int carry = 0;
    for (int i = 0; i < c.len; i++) {
        c.num[i] = num[i] + b.num[i] + carry;
        carry = c.num[i] / 10;
        c.num[i] %= 10;
    }
    if (carry) {
        c.num[c.len++] = carry;
    }
    return c;
}

bign bign::operator-(const bign &b) const {
    bign c;
    c.len = len;
    int borrow = 0;
    for (int i = 0; i < c.len; i++) {
        c.num[i] = num[i] - b.num[i] - borrow;
        if (c.num[i] < 0) {
            c.num[i] += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
    }
    while (c.len > 1 && c.num[c.len - 1] == 0) {
        c.len--;
    }
    return c;
}

bign bign::operator*(const bign &b) const {
    bign c;
    c.len = len + b.len;
    memset(c.num, 0, sizeof(c.num));
    for (int i = 0; i < len; i++) {
        int carry = 0;
        for (int j = 0; j < b.len; j++) {
            int temp = num[i] * b.num[j] + c.num[i + j] + carry;
            c.num[i + j] = temp % 10;
            carry = temp / 10;
        }
        if (carry) {
            c.num[i + b.len] += carry;
        }
    }
    while (c.len > 1 && c.num[c.len - 1] == 0) {
        c.len--;
    }
    return c;
}

bign bign::operator/(const bign &b) const {
    bign c;
    c.len = len;
    bign temp;
    for (int i = len - 1; i >= 0; i--) {
        temp = temp * 10 + num[i];
        int count = 0;
        while (temp >= b) {
            temp = temp - b;
            count++;
        }
        c.num[i] = count;
    }
    while (c.len > 1 && c.num[c.len - 1] == 0) {
        c.len--;
    }
    return c;
}

bool bign::operator<(const bign &b) const {
    if (len != b.len) return len < b.len;
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] != b.num[i]) return num[i] < b.num[i];
    }
    return false;
}

bool bign::operator>(const bign &b) const {
    return b < *this;
}

bool bign::operator<=(const bign &b) const {
    return !(*this > b);
}

bool bign::operator>=(const bign &b) const {
    return !(*this < b);
}

bool bign::operator==(const bign &b) const {
    if (len != b.len) return false;
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] != b.num[i]) return false;
    }
    return true;
}

bool bign::operator!=(const bign &b) const {
    return !(*this == b);
}

istream &operator>>(istream &in, bign &a) {
    string s;
    in >> s;
    a = s.c_str();
    return in;
}

ostream &operator<<(ostream &out, const bign &a) {
    for (int i = a.len - 1; i >= 0; i--) {
        out << a.num[i];
    }
    return out;
}

int main() {
    bign a, b, c;
    a = "123456789123456789987654321999999999999999999999999";
    cin >> b;
    c = 12345;

    cout << (a + b) << endl;
    cout << (a - b) << endl;
    cout << (a * b) << endl;
    cout << (a / b) << endl;
    cout << (a < b) << endl;
    cout << (a > c) << endl;

    a += b;
    cout << a << endl;
    cout << (a <= b) << endl;
    cout << (a >= c) << endl;

    a += c;
    cout << a << endl;
    cout << (a == b) << endl;
    cout << (a != c) << endl;

    return 0;
}
