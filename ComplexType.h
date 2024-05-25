#pragma once
#include <cmath>
#include <iostream>

class Complex {
private:
    double Re = 0.0;
    double Im = 0.0;
public:
    Complex() = default;
    Complex(double re , double im): Re(re),Im(im){}
    Complex(const Complex& a){
        Re = a.Re;
        Im = a.Re;
    }
    double& getRe(){
        return Re;
    }
    double& getIm(){
        return Im;
    }
    double getAbs(){
        return sqrt(pow(Re,2)+pow(Im,2));
    } 
    Complex GetСonjugate(){
        return  Complex(this->Re,-(this->Im));
    }
    bool operator==(const Complex& a){
        return (this->Re == a.Re)&&(this->Im == a.Im);
    }
    Complex& operator=(const Complex& a)
    {
        Re = a.Re;
        Im = a.Im;
        return (*this);
    }
    Complex operator+(const Complex& a)
    {
        Complex result ;
        result.Re = Re + a.Re;
        result.Im = Im + a.Im;
        return result;
    }
    Complex operator*(const Complex& a)
    {
        Complex result ;
        result.Re = Re * a.Re - Im * a.Im;
        result.Im = Re * a.Im + Im * a.Re;
        return result;
    }
    friend std::ostream& operator<< (std::ostream& stream, Complex cmp){
        stream<<" ("<<cmp.Re << ") + i * ("<<cmp.Im<<") ";
    }

};

void PrintComplex (Complex cmp){
    std::cout<<" ("<<cmp.getRe() << ") + i * ("<<cmp.getIm()<<") ";
}