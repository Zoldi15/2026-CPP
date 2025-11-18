//
// Created by User on 18-Nov-25.
//

#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <map>
#include <ostream>
#include <stdexcept>
#include <string>

using namespace std;

class Student {
private:
    int id;
    string firstName;
    string lastName;
    map<string, double> grades;
    double average {0.0};
public:
    Student(int id, const string &firstName, const string &lastName):id(id), firstName(firstName), lastName(lastName) {}
    int getId() const {return id;}
    void setId(int id) {this->id = id;}
    const string &getFirstName() const {return firstName;}
    const string &getLastName() const {return lastName;}

    void addGrade(const string& subject, double grade) {
        grades.insert({subject, grade});
    }
    //!!!!!!!!!!!!!!!!!!
    double getGrade(const string& subject) const {
        try {
            return grades.at(subject);
        } catch (out_of_range& e) {
            cout<<"Grade not found: "<<e.what()<<endl;
            return -1;
        }
    }//throws out_of_range for nonexistent subject
    const map<string, double> &getGrades() const {return grades;}

    void computeAverage() {
        double sum=0.0;
        int count=0;
        for(auto& grade : grades) {
            if(grade.second<5) return;
            sum += grade.second;
            count++;
        }
        sum = sum/count;
        if(sum>=6) average = sum;
    }
    double getAverage() const {return average;}
    friend ostream& operator<<(ostream& os, const Student& student) {
        os<<"ID: "<<student.getId()<<endl;
        return os;
    }
};

#endif //STUDENT_H
