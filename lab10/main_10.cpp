#include <iostream>
#include "GraduationDao.h"

using namespace std;

int main() {
    /*
    string subjects[]{"maths", "romanian", "hungarian"};
    int numSubjects = sizeof(subjects) / sizeof(subjects[0]);
    GraduationDao dao(2023);
    dao.enrollStudents("names.txt");
    cout << "Number of enrolled students: " << dao.numEnrolled() << endl;
    for (int i = 0; i < numSubjects; ++i) {
    dao.readGradesSubject(subjects[i], subjects[i] + ".txt");
    }
    dao.computeAverage();
    cout <<"Number of passed students: " << dao.numPassed() << endl;
    */

    Student s1(1,"Babos","John");
    Student s2(2,"Gulyas","Leves");
    s1.addGrade("Magyar",2); s1.addGrade("Roman",4);
    s1.computeAverage(); cout<<s1.getAverage()<<endl;
    map<string,double> s1grade=s1.getGrades();
    cout<<s1grade["Magyar"]<<" "<<s1grade["Roman"]<<endl;

    GraduationDao d1(2025);
    d1.enrollStudents("nevek.txt");
    d1.readGradesSubject("Roman","roman.txt");
    d1.readGradesSubject("Magyar","magyar.txt");
    d1.readGradesSubject("Matek","matek.txt");
    d1.computeAverage();
    cout<<"Enrolled: "<<d1.numEnrolled()<<" Passed: "<<d1.numPassed()<<endl;

    cout<<"Roman atlag: "<<d1.getAverageBySubject("Roman")<<endl;
    cout<<"Magyar atlag: "<<d1.getAverageBySubject("Magyar")<<endl;
    cout<<"Matek atlag: "<<d1.getAverageBySubject("Matek")<<endl;

    return 0;
}