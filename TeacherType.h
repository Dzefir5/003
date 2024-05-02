
#pragma once
#include "string"

class Teacher{
public:
    int age = 0;
    std::string name = "";
    std::string surname = "";
    std::string subject = "";
    Teacher(){};
    Teacher(const Teacher &a){
        this->age = a.age;
        this->name = a.name;
        this->surname = a.surname;
        this->subject = a.subject;
    }
    Teacher(int age , std::string name, std::string surname, std::string subject){
        this->age = age;
        this->surname = surname;
        this->name = name;
        this->subject = subject;
    }

    bool operator == (Teacher& a) const
    {
        if(
            this->age == a.age &&
            this->subject == a.subject &&
            this->name == a.name && 
            this->surname == a.surname
            ){
            return true;
        }
        return false;

    }
    Teacher& operator = (const Teacher& a)
    {
        age = a.age;
        name = a.name;
        surname = a.surname;
        subject = a.subject;
        return (*this);
    }


};
