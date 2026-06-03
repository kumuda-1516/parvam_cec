#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

template <typename T>
class ScoreManager {
private:
    vector<T> scores;

public:
    void addScore(T score) {
        scores.push_back(score);
    }

    

        
        
T getAverage() {
    if (scores.empty()) return T();
    T sum = 0;
    for (T s : scores) sum += s;
    return sum / scores.size();
}

T getHighest() {
    return *max_element(scores.begin(), scores.end());
}

T getLowest() {
    return *min_element(scores.begin(), scores.end());
}

void displayAll() {
    cout << "Scores: ";
    for (T s : scores)
        cout << s << " ";
    cout << endl;
}

int getCount() {return scores.size();}
};

int main() {
    ScoreManager<int> mathScores;
    mathScores.addScore(85);
    mathScores.addScore(92);
    mathScores.addScore(78);
    mathScores.addScore(95);
    mathScores.addScore(88);

    cout << "=== Math Scores (int) ===" << endl;
    mathScores.displayAll();
    
    cout << "Count :" << mathScores.getCount() << endl;
    cout << "Average :" << mathScores.getAverage() << endl;
    cout << "Highest :" << mathScores.getHighest() << endl;
    cout << "Lowest :" << mathScores.getLowest() << endl;


    ScoreManager<double> scienceScores;
    scienceScores.addScore(88.5);
    scienceScores.addScore(91.2);
    scienceScores.addScore(76.8);

    cout << "\n== Science Scores (double) ===" << endl;
    scienceScores.displayAll();

    cout << "Average :" << scienceScores.getAverage() << endl;

    return 0;


}