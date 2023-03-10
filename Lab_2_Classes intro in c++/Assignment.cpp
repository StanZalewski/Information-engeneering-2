#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

// Assignment task Add a print method that prints the student's name and all his
// grades inside the Student structure:alignas

struct Student {
    std::string name;
    std::string surname;
    std::vector<float> grades;

    float calculate_grade() {
        float sum = std::accumulate(grades.begin(), grades.end(), 0.0f);
        return sum / grades.size();
    }

    void print_students() {
        cout << name << " " << surname << ":";
        for (int i; i <= grades.size(); i++) {
            cout << i << " ";
        }
        cout << endl;
    }
};

int main() {
    Student student{"Some", "Student", {2, 3, 4, 5, 3}};
    return 0;
}