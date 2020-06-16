#include <string>
#include <bits/stdc++.h>

using namespace std;

string add_binary(string a, string b) {
    if (a == "0") {
        return b;
    }
    if (b == "0") {
        return a;
    }

    string res;

    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;

    while (i >= 0 && j >= 0) {
        int digitVal = (a[i] - '0') + (b[j] - '0') + carry;
        res += to_string(digitVal % 2);
        carry = digitVal / 2;
        i --;
        j --;
    }

    while (i >= 0) {
        int digitVal = (a[i] - '0') + carry;
        res += to_string(digitVal % 2);
        carry = digitVal / 2;
        i --;
    }

    while (j >= 0) {
        int digitVal = (b[j] - '0') + carry;
        res += to_string(digitVal % 2);
        carry = digitVal / 2;
        j --;
    }

    if (carry != 0) {
        res += to_string(carry);
    }

    reverse(res.begin(), res.end());

    return res;
}
