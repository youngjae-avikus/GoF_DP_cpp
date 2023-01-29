#include <iostream>

class Animal
{
protected:
    int age;
public:
    virtual void Cry() {std::cout << "Animal Cry" << std::endl;}
};

class Dog : public Animal
{
    int color;
public:
    virtual void Cry() override {std::cout << "Dog Cry" << std::endl;}
};

int main()
{   
    Dog d;
    Animal *p = &d;
    p->Cry();
    return 0;
}