// // https://leetcode.com/problems/reverse-vowels-of-a-string/
#include "bits/stdc++.h"
#include <unordered_set>
#include "iostream"
using namespace std;

string reverseVowels(string s) {
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    int i = 0, j = s.size() - 1;

    while (i < j) {
        // Move i forward until it points to a vowel
        while (i < j && vowels.find(s[i]) == vowels.end()) {
            i++;
        }
        // Move j backward until it points to a vowel
        while (i < j && vowels.find(s[j]) == vowels.end()) {
            j--;
        }

        // Swap the vowels
        if (i < j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }

    return s;
}

int main() {
    string str = "IceCreAm";
    string ans = reverseVowels(str);
    cout << "Result: " << ans << endl;
    return 0;
}
