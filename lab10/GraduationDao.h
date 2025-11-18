//
// Created by User on 18-Nov-25.
//

#ifndef GRADUATIONDAO_H
#define GRADUATIONDAO_H

#include <fstream>
#include "Student.h"

class GraduationDao {
    int year{2025};
    map<int, Student> students;
public:
    explicit GraduationDao(int year) : year(year) {}

    void enrollStudents(const string &filename) {
        ifstream f(filename);

        int id; string firstname, lastname;
        while(f>>id>>firstname>>lastname) {
            //cout<<id<<" "<<firstname<<" "<<lastname<<endl;
            students.insert({id,Student(id,firstname,lastname)});
        }

        f.close();
    };
    void readGradesSubject(const string &subject, const string &filename) {
        ifstream f(filename);

        int id; double grade;
        while(f>>id>>grade) {
            students.at(id).addGrade(subject,grade);
        }

        f.close();
    }
    void computeAverage() {
        for(auto& student : students) {
            student.second.computeAverage();
        }
    }

    int numEnrolled() const {return students.size();}
    int numPassed() const {
        int count=0;
        for(auto& student : students) {
           if(student.second.getAverage()!=0) count++;
        }
        return count;
    };
    Student findById(int id) const {return students.at(id);}//throws out_of_range exception for nonexistent id
    double getAverageBySubject(const string &subject) const {
        double sum=0;
        for (auto& student : students) {
            sum+=student.second.getGrade(subject);
        }
        return sum/students.size();
    }
};


#endif //GRADUATIONDAO_H
