//beautifulDays
#include <iostream>
#include <string>

int beautifulDays(int i, int j, int k) {
    int beautifulCount = 0;

    for (int day = i; day <= j; day++) {
        int reversed = 0;
        int temp = day;

        while (temp > 0) {
            reversed = reversed * 10 + temp % 10;
            temp /= 10;
        }

        int difference = abs(day - reversed);
       
        if (difference % k == 0) {
            beautifulCount++;
        }
    }

    return beautifulCount;
}

int main() {
    int result = beautifulDays(20, 23, 6);
    std::cout << result << std::endl; // Output: 2

    return 0;
}


//hourglassSum
#include <iostream>
#include <vector>

int hourglassSum(std::vector<std::vector<int>>& arr) {
    int maxSum = -INT_MAX;

    for (int i = 0; i <= 3; i++) {
        for (int j = 0; j <= 3; j++) {
            int currentSum = 
                arr[i][j] + arr[i][j+1] + arr[i][j+2] +
                            arr[i+1][j+1] +
                arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];

            if (currentSum > maxSum) {
                maxSum = currentSum;
            }
        }
    }

    return maxSum;
}

int main() {
    std::vector<std::vector<int>> arr = {
        {1, 1, 1, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {1, 1, 1, 0, 0, 0},
        {0, 0, 2, 4, 4, 0},
        {0, 0, 0, 2, 0, 0},
        {0, 0, 1, 2, 4, 0}
    };

    int maxHourglassSum = hourglassSum(arr);
    std::cout << maxHourglassSum << std::endl; // Output: 19

    return 0;
}

//saveThePrisoner
#include <iostream>
using namespace std;

int saveThePrisoner(int n, int m, int s) {
    int result = (m + s - 1) % n;
    if (result == 0) {
        result = n;
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int n, m, s;
        cin >> n >> m >> s;
        int prisonerToWarn = saveThePrisoner(n, m, s);
        cout << prisonerToWarn << endl;
    }

    return 0;
}

//viralAdvertising
#include <iostream>
using namespace std;

int viralAdvertising(int n) {
    int shared = 5;
    int liked = shared / 2;
    int cumulativeLikes = liked;

    for (int day = 2; day <= n; day++) {
        shared = liked * 3; // Each person shares with 3 friends
        liked = shared / 2;
        cumulativeLikes += liked;
    }

    return cumulativeLikes;
}

int main() {
    int dayNumber = 3;
    int result = viralAdvertising(dayNumber);
    cout << result << endl; // Output: 9

    return 0;
}

//jumpingOnClouds
#include <iostream>
#include <vector>

int jumpingOnClouds(std::vector<int>& c, int k) {
    int energy = 100;
    int currentPosition = 0;
    const int n = c.size();

    do {
        currentPosition = (currentPosition + k) % n;
        energy -= c[currentPosition] * 2 + 1;
    } while (currentPosition != 0);

    return energy;
}

int main() {
    // Example usage
    std::vector<int> clouds = {0, 0, 1, 0, 0, 1, 1, 0};
    int jumpDistance = 2;
    int finalEnergy = jumpingOnClouds(clouds, jumpDistance);

    std::cout << finalEnergy << std::endl; // Output: 92

    return 0;
}

#include <iostream>
#include <string>
using namespace std;

//appendAndDelete
string appendAndDelete(string s, string t, int k) {
    int commonLength = 0;

    // Find the length of the common prefix
    for (int i = 0; i < min(s.length(), t.length()); i++) {
        if (s[i] == t[i]) {
            commonLength++;
        } else {
            break;
        }
    }

    // Calculate the total operations needed
    int totalOperations = s.length() + t.length() - 2 * commonLength;

    // Check if it's possible
    if (totalOperations <= k && (totalOperations - k) % 2 == 0 || k >= s.length() + t.length()) {
        return "Yes";
    } else {
        return "No";
    }
}

int main() {
    // Example usage
    cout << appendAndDelete("hackerhappy", "hackerrank", 9) << endl; // Output: Yes
    cout << appendAndDelete("aba", "aba", 7) << endl; // Output: Yes

    return 0;
}


