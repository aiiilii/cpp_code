#include <string>
#include <bits/stdc++.h> 

using namespace std;

string addStrings(string num1, string num2) {
    if (num1 == "0") {
        return num2;
    }
    if (num2 == "0") {
        return num1;
    }
    
    string res = "";
    int carry = 0;
    
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    
    while (i >= 0 && j >= 0) {
        int digitVal = (num1[i] - '0') + (num2[j] - '0') + carry;
        res += to_string(digitVal % 10);
        carry = digitVal / 10;
        i --;
        j --;
    }
    
    while (i >= 0) {
        int digitVal = (num1[i] - '0') + carry;
        res += to_string(digitVal % 10);
        carry = digitVal / 10;
        i --;
    }
    
    while (j >= 0) {
        int digitVal = (num2[j] - '0') + carry;
        res += to_string(digitVal % 10);
        carry = digitVal / 10;
        j --;
    }
    
    if (carry != 0) {
        res += to_string(carry);
    }
    
    reverse(res.begin(), res.end());
    return res;
}
