#include <iostream>
#include <vector>
#include <algorithm> // For std::sort

using namespace std;

class Solution {
public:
    void solve() {
        long long width, height;
        cin >> width >> height;

        vector<long long> bottomPoints, topPoints, leftPoints, rightPoints;
        int numPoints;

        // Read bottom points
        cin >> numPoints;
        for (int i = 0; i < numPoints; ++i) {
            long long x;
            cin >> x;
            bottomPoints.push_back(x);
        }
        sort(bottomPoints.begin(), bottomPoints.end());  // Use std::sort

        // Read other points similarly... (topPoints, leftPoints, rightPoints)
        cin >> numPoints;
        for (int i = 0; i < numPoints; ++i) {
            long long x;
            cin >> x;
            topPoints.push_back(x);
        }
        sort(topPoints.begin(),topPoints.end());
        cin >> numPoints;
        for (int i = 0; i < numPoints; ++i) {
            long long x;
            cin >> x;
            leftPoints.push_back(x);
        }
        sort(leftPoints.begin(),leftPoints.end());
        cin >> numPoints;
        for (int i = 0; i < numPoints; ++i) {
            long long x;
            cin >> x;
            rightPoints.push_back(x);
        }
        sort(rightPoints.begin(),rightPoints.end());
        // Calculate maximum distances and area
        long long maxUpDownDistance = max(bottomPoints.back() - bottomPoints.front(),
                                          topPoints.back() - topPoints.front());
        long long maxLeftRightDistance = max(rightPoints.back() - rightPoints.front(),
                                             leftPoints.back() - leftPoints.front());
        long long maxArea = max(maxLeftRightDistance * width, maxUpDownDistance * height);

        cout <<  maxArea << endl;  // Double the area as required
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int numTestCases;
    cin >> numTestCases;

    for (int i = 0; i < numTestCases; ++i) {
        Solution solution;
        solution.solve();
    }

    return 0;
}
