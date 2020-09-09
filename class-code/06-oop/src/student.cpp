#include <string>
#include <string.h>
#include <stdlib.h>

#include "student.hpp"

Student::Student() {
}

Student::Student(std::string name) {
    this->name = name;
}

bool Student::is_asleep() {
    return true;
}

bool Student::has_homework() {
    return true;
}

std::string Student::get_name() {
    return name;
}

Student& Student::operator=(Student *st) {
    this->name = st->name;
}

Student::~Student() {
}

