#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <numeric>
#include <iomanip>

using namespace std;

int main() {
    vector<pair<string, int>> grades = {
        {"Arjun", 85},
        {"Priya", 92},
        {"Rahul", 78},
        {"Sneha", 95},
        {"Vikram", 88},
        {"Ananya", 76},
        {"Kiran", 90}
    };

    cout << "=== Grade Report ===" << endl;

    cout << "\nAll Students:" << endl;
    for (const auto &student : grades) {
        cout << student.first << " : " << student.second << endl;
    }

    // Sort by score (highest first)
    sort(grades.begin(), grades.end(),
         [](const pair<string, int>& a, const pair<string, int>& b) {
             return a.second > b.second;
         });

    cout << "\nRanking:" << endl;
    int rank = 1;
    for (const auto &student : grades) {
        cout << rank++ << ". "
             << student.first << " (" << student.second << ")" << endl;
    }

    vector<int> scores;
    for (const auto &student : grades) {
        scores.push_back(student.second);
    }

    double average =
        accumulate(scores.begin(), scores.end(), 0.0) / scores.size();

    auto minScore = min_element(scores.begin(), scores.end());
    auto maxScore = max_element(scores.begin(), scores.end());

    cout << fixed << setprecision(2);

    cout << "\nStatistics:" << endl;
    cout << "Average Score : " << average << endl;
    cout << "Highest Score : " << *maxScore << " (" << grades.front().first << ")" << endl;
    cout << "Lowest Score  : " << *minScore << " (" << grades.back().first << ")" << endl;

    map<char, int> distribution;

    for (int score : scores) {
        if (score >= 90)
            distribution['A']++;
        else if (score >= 80)
            distribution['B']++;
        else if (score >= 70)
            distribution['C']++;
        else
            distribution['D']++;
    }

    cout << "\nGrade Distribution:" << endl;
    for (const auto &entry : distribution) {
        cout << entry.first << " : "
             << entry.second << " student(s)" << endl;
    }

    return 0;
}