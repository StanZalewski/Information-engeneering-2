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
    double ID_album;
    std::vector<float> grades;

public:
    Student(std::string n, std::string s,  std::vector<float> g){
        name=n;
        surname=s;
        grades=g;
    }
    //setting name, surname, album ID and grades function
    void personal_info(){
        cout<<"What your name?"<<endl;
        cin>>name;
        cout<<"What your surname?"<<endl;
        cin>>surname;
        cout<<"What your ID number?"<<endl;
        cin>>ID_album;
        cout<<"What are your 5 grades?"<<endl;

        int i=0;
        while(i<5){
            float grade=0;
            cin>>grade;
            if (grade >= 2.0 && grade <= 5.0) {
                grades[i]=grade;
                i++;
            }
            else{
                cout<<"Incorrect!!!!! enter again"<<endl;
            }

        }

    }

    // mean calculating function
    float calculate_grade() {
        float sum = std::accumulate(grades.begin(), grades.end(), 0.0f);
        return sum / grades.size();
    }

    //function to print below
    void print() {
        std::cout<<"Name:" << name<<" Surname: "<<surname<<" ID_number: "<<ID_album<<" Student Grades: ";
        for (int i=0; i<grades.size();i++){
            std::cout<<grades[i]<<" ";
        }
        std::cout<<std::endl;
    }

    //function that adds the grades
    bool add_grade(float grade) {
        if (grade >= 2.0 && grade <= 5.0) {
            // The grade is valid; let's add it and return true
            grades.push_back(grade);
            return true;
        }
        // The grade is invalid; let's return false
        return false;
    }
    //function that checks if student passed a semester
    bool check_semester(){
        if (1<std::count(grades.begin(),grades.end(),2)){
            return false;
            }
        else{
            return true;
        }

    }
};

int main()
{
    Student student{"Some", "Student", {0,0,0,0,0}}; // This creates object of Student type
    student.personal_info();
    student.print();
    student.add_grade(4.0);
    student.print();
    std::cout << student.calculate_grade() << std::endl; // This calls calculate_grade function and prints the result
    student.print();
    std::cout << student.check_semester() << std::endl;
    return 0;
}
