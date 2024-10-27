#include "OpenScatterTable.h"
#include <string>

class Student {
public:
    int index;
    std::string name;

    Student(int idx, const std::string& nm) : index(idx), name(nm) {}

    void print() const {
        std::cout << "Index: " << index << ", Name: " << name << std::endl;
    }
};

bool addOrUpdateStudent(OpenScatterTable& table, int index, const std::string& name) {
    Student newStudent(index, name);
    ScatterObject obj((std::to_string(index)).c_str());
    obj.setAttributes(name);

    if (!table.insert(obj)) {
        table.update(obj);
        return false;
    }
    return true;
}

Student* findStudentByIndex(OpenScatterTable& table, int index) {
    std::string key = std::to_string(index);
    ScatterObject* obj = table.find(key.c_str());
    if (obj != nullptr) {
        return new Student(index, obj->getName());
    }
    return nullptr;
}
