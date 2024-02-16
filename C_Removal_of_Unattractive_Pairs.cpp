#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::string s;
        std::cin >> s;

        // Count occurrences of each character
        std::vector<int> counts(26, 0);
        for (char c : s) {
            counts[c - 'a']++;
        }

        // Sort the counts in ascending order
        std::sort(counts.begin(), counts.end());

        // Calculate the minimum length based on the conditions
        int ans =max(n % 2, counts[25] - accumulate(counts.begin(), counts.end() - 1, 0));

        std::cout << ans << std::endl;
    }

    return 0;
}
