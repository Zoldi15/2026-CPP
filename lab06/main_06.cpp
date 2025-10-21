#include <iostream>
#include "QuizGame.h"

using namespace std;

int main() {

    QuizItem q1={"What is the correct way to declare a constant variable in C++?",
        {
        "A) int const x = 10;",
        "B) const int x = 10;",
        "C) int x = const 10;",
        "D) Both A and B};"},
        3};
    QuizItem q2={"Which of the following best describes encapsulation?",
        {
        "A) Hiding implementation details and exposing only necessary parts",
        "B) Using multiple classes with the same name",
        "C) Writing one function that performs many unrelated tasks",
        "D) Overloading operators for custom types"},
        0};
    QuizItem q3={"In C++, what does the static keyword mean when used inside a class?",
        {
        "A) The member belongs to instances of the class",
        "B) The member is shared among all instances of the class",
        "C) The member cannot be accessed outside the class",
        "D) The member cannot change once initialized"},
        1};

    Quiz quiz1={"Quiz A"};
    quiz1.addItem(q1); quiz1.addItem(q2); quiz1.addItem(q3);
    quiz1.finalize();

    User user1={"ABC"};

    QuizGame game1(quiz1,user1);
    game1.runQuiz();
    return 0;
}