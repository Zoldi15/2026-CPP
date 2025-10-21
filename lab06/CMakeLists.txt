project(lab6)
add_executable(lab6 main_06.cpp
        Sources/QuizItem.cpp
        Headers/QuizItem.h
        Sources/Quiz.cpp
        Headers/Quiz.h
        Sources/User.cpp
        Headers/User.h
        Sources/QuizGame.cpp
        Headers/QuizGame.h
)
include_directories(Headers)
