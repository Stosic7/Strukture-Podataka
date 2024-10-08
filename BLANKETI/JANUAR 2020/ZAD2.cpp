#pragma once
#include "HashObject.h"

class ScatterObject : public HashObject {
private:
    char* name; // ime zaposlenog
    char* lastName; // prezime zaposlenog
public:
    int status; // 0 - slobodan, 1 - obrisan, 2 - zauzet
    ScatterObject();
    ScatterObject(const char* k, const char* name, const char* lastName);
    ScatterObject(ScatterObject const& obj);
    ScatterObject& operator=(ScatterObject const& obj);
    void setName(const char* name) {
        if (this->name) delete[] this->name;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
    void setLastName(const char* lastName) {
        if (this->lastName) delete[] this->lastName;
        this->lastName = new char[strlen(lastName) + 1];
        strcpy(this->lastName, lastName);
    }
    char* getName() { return name; }
    char* getLastName() { return lastName; }
    void print();
    ~ScatterObject() {
        delete[] name;
        delete[] lastName;
    }
};

#include "OpenScatterTable.h"
#include <cstring>
#include <iostream>

bool OpenScatterTable::isTaken(char* email, char* name, char* lastName) {
    unsigned int index = h(email);
    unsigned int i = 0;

    while (i < m) {
        unsigned int currentIndex = (index + c(i)) % m;
        if (array[currentIndex].status == 0) {
            
            return false;
        } else if (array[currentIndex].isEqualKey(email)) {
            
            strcpy(name, array[currentIndex].getName());
            strcpy(lastName, array[currentIndex].getLastName());
            return true;
        }
        i++;
    }
    return false; 
}

bool OpenScatterTable::Register(char* email, char* name, char* lastName) {
    unsigned int index = h(email);
    unsigned int i = 0;

    while (i < m) {
        unsigned int currentIndex = (index + c(i)) % m;
        if (array[currentIndex].status == 0) {
            
            array[currentIndex] = ScatterObject(email);
            array[currentIndex].setName(name);
            array[currentIndex].setLastName(lastName);
            array[currentIndex].status = 2; // Zauzet
            count++;
            return true;
        } else if (array[currentIndex].isEqualKey(email)) {
            
            return false;
        }
        i++;
    }
    return false; 
}

#include "ScatterObject.h"

ScatterObject::ScatterObject() : HashObject() {
    status = 0;
    name = nullptr;
    lastName = nullptr;
}

ScatterObject::ScatterObject(const char* k, const char* name, const char* lastName) : HashObject(k) {
    status = 2; // Zauzet
    setName(name);
    setLastName(lastName);
}

void ScatterObject::print() {
    if (status == 2) {
        HashObject::print(); // Prikazuje email
        std::cout << " - " << name << " " << lastName << std::endl; // Prikazuje ime i prezime
    }
}

