#include <iostream>

class Car
{
public:
    Car() {}

    // 클래스 내부에서는 Protected를 호출할 수 있음
    void Destory() { delete this; }
protected:
    // 소멸자를 protected로 선언하면 
    // 소멸자 호출을 만들 객체를 만들 수가 없음
    ~Car() { std::cout << "소멸자 호출\n"; }
};

int main()
{
    // Car c;  // 스택에 객체를 만들 수 없다
    Car *p = new Car;

    // delete p; // 힙에 만들어도 delete할 때 에러가 발생

    p->Destory();
    return 0;
}

