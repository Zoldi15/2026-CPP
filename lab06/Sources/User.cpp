//
// Created by User on 21-Oct-25.
//

#include "User.h"

#include <iostream>
#include <ostream>

int User::nextId=100;

User::User(string name) {
    this->name=name;
    id=nextId++;
}

void User::addResult(Quiz &quiz, double result) {
    this->results.emplace(quiz,result);
}

void User::printResults(std::ostream& os) const{
    for (auto& p:this->results) {
        os<<p.first<<":"<<p.second<<endl;
    }
}

std::ostream & User::operator<<(ostream &os) const {
    os<<"Name: "<<this->name<<endl;
    return os;
}
