#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    double score = 0;
    double sum = 0;
    for(int i=0; i<20; i++) {
        string name, grade;
        double time;
        cin >> name >> time >> grade;
        if(grade == "A+") {
            score += 4.5*time;
            sum += time;
        }
        else if(grade == "A0") {
            score += 4.0*time;
            sum += time;
        }
        else if(grade == "B+") {
            score += 3.5*time;
            sum += time;
        }
        else if(grade == "B0") {
            score += 3.0*time;
            sum += time;
        }
        else if(grade == "C+") {
            score += 2.5*time;
            sum += time;
        }
        else if(grade == "C0") {
            score += 2.0*time;
            sum += time;
        }
        else if(grade == "D+") {
            score += 1.5*time;
            sum += time;
        }
        else if(grade == "D0") {
            score += 1.0*time;
            sum += time;
        }
        else if(grade == "F") {
            sum += time;
        }
    }
    cout << score/sum;
}
