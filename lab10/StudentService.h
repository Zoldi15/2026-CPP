//
// Created by User on 18-Nov-25.
//

#ifndef STUDENTSERVICE_H
#define STUDENTSERVICE_H

class StudentService {
public:
    virtual bool isEnrolled(int id) const = 0;
    virtual double getResultBySubject(int id, const string& subject) const = 0;
    virtual vector<string> getSubjects(int id) const = 0;
    virtual double getAverage(int id) const = 0;
    virtual bool isPassed(int id) const = 0;
};

#endif //STUDENTSERVICE_H
