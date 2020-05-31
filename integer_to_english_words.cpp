#include <string>
#include <unordered_map>

using namespace std;

string number_to_words(int num) {
    if (num == 0) {
        return "Zero";
    }

    unordered_map<int, string> onesMap;
    onesMap.emplace(1, "One");
    onesMap.emplace(2, "Two");
    onesMap.emplace(3, "Three");
    onesMap.emplace(4, "Four");
    onesMap.emplace(5, "Five");
    onesMap.emplace(6, "Six");
    onesMap.emplace(7, "Seven");
    onesMap.emplace(8, "Eight");
    onesMap.emplace(9, "Nine");

    unordered_map<int, string> teensMap;
    teensMap.emplace(10, "Ten");
    teensMap.emplace(11, "Eleven");
    teensMap.emplace(12, "Twelve");
    teensMap.emplace(13, "Thirteen");
    teensMap.emplace(14, "Fourteen");
    teensMap.emplace(15, "Fifteen");
    teensMap.emplace(16, "Sixteen");
    teensMap.emplace(17, "Seventeen");
    teensMap.emplace(18, "Eighteen");
    teensMap.emplace(19, "Nineteen");

    unordered_map<int, string> tensMap;
    tensMap.emplace(2, "Twenty");
    tensMap.emplace(3, "Thirty");
    tensMap.emplace(4, "Forty");
    tensMap.emplace(5, "Fifty");
    tensMap.emplace(6, "Sixty");
    tensMap.emplace(7, "Seventy");
    tensMap.emplace(8, "Eighty");
    tensMap.emplace(9, "Ninety");

    string res;
    string billion = "Billion";
    string million = "Million";
    string thousand = "Thousand";

    if (num / 1000000000 > 0) {
        res += onesMap[num / 1000000000] + " " + billion;
        if (num % 1000000000 > 0) {
            res += " ";
        }
        num %= 1000000000;
    }

    if (num / 1000000 > 0) {
        res += parse_three(num / 1000000, onesMap, teensMap, tensMap) + " " + million;
        if (num % 1000000 > 0) {
            res += " ";
        }
        num %= 1000000;
    }

    if (num / 1000 > 0) {
        res += parse_three(num / 1000, onesMap, teensMap, tensMap) + " " + thousand;
        if (num % 1000 > 0) {
            res += " ";
        }
        num %= 1000;
    }

    if (num > 0) {
        res += parse_three(num, onesMap, teensMap, tensMap);
    }

    return res;
}

string parse_three(int num, unordered_map<int, string> onesMap, unordered_map<int, string> teensMap, unordered_map<int, string> tensMap) {
    string res;

    if (num / 100 > 0) {
        res += onesMap[num / 100] + " Hundred";
        if (num % 100 > 0) {
            res += " ";
        }
        num %= 100;
    }
    if (num > 0) {
        res += parse_two(num, onesMap, teensMap, tensMap);
    }
    return res;
}

string parse_two(int num, unordered_map<int, string> onesMap, unordered_map<int, string> teensMap, unordered_map<int, string> tensMap) {
    string res;

    if (num < 10) {
        res += onesMap[num];
    } else if (num < 20) {
        res += teensMap[num];
    } else {
        res += tensMap[num / 10];
        if (num % 10 > 0) {
            res += " ";
            res += onesMap[num % 10];
        }
    }
    return res;
}