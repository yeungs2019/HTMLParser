#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>

#include "student.hpp"
#include "teacher.hpp"

int main(int argc, char *argv[]) {
    Student st("Rick");
    Teacher t;
    Student *st2 = new Student("Jeremy");

    t.change_name(&st);

    std::cout << st.is_asleep() << "\n";
    std::cout << st.get_name() << "\n";
    //std::cout << t.get_name() << "\n";
    std::cout << st2->is_asleep() << "\n";
    std::cout << st2->get_name() << "\n";

    st = st2;

    std::cout << st.is_asleep() << "\n";
    std::cout << st.get_name() << "\n";

    delete st2;
    return 0;
}
