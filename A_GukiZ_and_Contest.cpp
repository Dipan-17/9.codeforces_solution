#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> ratings(n);
    for (int i = 0; i < n; ++i) {
        cin >> ratings[i];
    }

    // Create a sorted copy to determine ranks
    vector<int> sortedRatings = ratings;
    sort(sortedRatings.rbegin(), sortedRatings.rend());

    // Map each rating to its rank
    map<int, int> ranks;
    int rank = 1;
    for (int i = 0; i < n; ++i) {
        if (ranks.find(sortedRatings[i]) == ranks.end()) {
            ranks[sortedRatings[i]] = rank;
        }
        rank++;
    }

    // Output the rank of each student's rating
    for (int i = 0; i < n; ++i) {
        cout << ranks[ratings[i]] << " ";
    }

    return 0;
}