#include <utility>
#include <vector>
#include <iostream>
using namespace std;

static pair<int, int> extended_euclidean(int a, int b) {
    if (b == 0) {
        return pair<int, int>(1, 0);
    }

    pair<int, int> res = extended_euclidean(b, a % b);
    int x = res.first, y = res.second;
    return pair<int, int>(y, x - a / b * y);
}

static int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    vector<pair<int, int>> test_cases = {
        {2, 5},
        {6, 3},
        {21, 28},
        {24, 9}
    };

    for (auto& test_case: test_cases) {
        pair<int, int> res = extended_euclidean(test_case.first, test_case.second);
        cout << test_case.first << " * " << res.first << " + " << test_case.second << " * " << res.second;
        cout <<  " = " << gcd(test_case.first, test_case.second) << endl << endl;
    }
}