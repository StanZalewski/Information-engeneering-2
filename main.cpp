#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <iterator>

using namespace std;

class Student {
    private:
        std::string name;
        std::string surname;
        std::vector<float> grades;

    public:
        Student(std::string n, std::string s,  std::vector<float> g){
            name=n;
            surname=s;
            grades=g;
        }

        float calculate_grade() {
            float sum = std::accumulate(grades.begin(), grades.end(), 0.0f);
            return sum / grades.size();
        }

        //function to print below
        void print() {
            std::cout << name << surname<<": ";
            for (int i=0; i<grades.size();i++){
                std::cout<<grades[i]<<" ";
            }
            std::cout<<std::endl;
        }

        // shorter but more advanced version of printing a vactor in a structure

        //void print() {
        //std::cout << "Name: " << name << ", Surname: " << surname << ", Grades: ";
        //std::copy(grades.begin(), grades.end(), std::ostream_iterator<float>(std::cout, " "));
        //std::cout << std::endl;
        //}
        bool add_grade(float grade) {
            if (grade >= 2.0 && grade <= 5.0) {
                // The grade is valid; let's add it and return true
                grades.push_back(grade);
                return true;
            }
            // The grade is invalid; let's return false
            return false;
        }
};

int main()
{
    Student student{"Some", "Student", {2, 3, 4, 5, 3}}; // This creates object of Student type
    std::cout << student.calculate_grade() << std::endl; // This calls calculate_grade function and prints the result
    student.print(); // This needed to inicialise a printing function
    student.add_grade(4.0);
    // If uncommented this creates an error - grades in private - only accesible through add_grade func which prevets from adding wrong numbers to a student
    //student.grades.push_back(4.0);
    student.print();

    return 0;
}
