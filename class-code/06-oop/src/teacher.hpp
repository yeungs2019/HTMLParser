#ifndef TEACHER_HPP
#define TEACHER_HPP

#include "student.hpp"

class Teacher: public Student {
    public:
        Teacher();
        void change_name(Student *st);
};

#endif
