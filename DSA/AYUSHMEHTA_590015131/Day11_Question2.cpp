#include <iostream>
using namespace std;

string expandFromCenter(string s, int left, int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
        left--;
        right++;
    }
    return s.substr(left + 1, right - left - 1);
}

string longestPalindrome(string s) {
    if (s.empty()) return "";

    string longest = "";
    for (int i = 0; i < s.size(); i++) {
        string odd = expandFromCenter(s, i, i);      
        string even = expandFromCenter(s, i, i + 1);  

        if (odd.size() > longest.size()) longest = odd;
        if (even.size() > longest.size()) longest = even;
    }
    return longest;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    cout << "Longest Palindromic Substring: " << longestPalindrome(s) << endl;
    return 0;
}