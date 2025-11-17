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
        ../lab09/FileSystemItem.cpp
        ../lab09/FileSystemItem.h
)
include_directories(Headers)
