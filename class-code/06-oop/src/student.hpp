#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>

class Student {
    public:
        Student();
        Student(std::string _name);
        bool is_asleep();
        bool has_homework();
        std::string get_name();
        Student& operator=(Student *st) ;
        ~Student();
    private:
        std::string name;
        int id;
};

#endif
