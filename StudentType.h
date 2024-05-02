
#pragma once
#include "string"

class Student{
public:
    int age=0;
    std::string name="";
    std::string surname="";
    int course=0;

    Student(){};
    Student(const Student &c){
        age = c.age;
        name = c.name;
        surname = c.surname;
        course = c.course;
    }
    Student(std::string a, std::string b, int c, int d){
        age = c;
        surname = a;
        name = b;
        course = d;
    }
  
    Student& operator = (int a)
    {
        age = 0;
        name = "***";
        surname = "***";
        course = 0;
        return (*this);
    }
    Student& operator = (const Student& c)
    {
        age = c.age;
        name = c.name;
        surname = c.surname;
        course = c.course;
        return (*this);
    }
    bool operator == (Student& a) const
    {
        if(
            this->age == a.age && 
            this->course == a.course &&
            this->name == a.name &&
            this->surname == a.surname
        ){
            return true;
        }
        return false;

    }


};
