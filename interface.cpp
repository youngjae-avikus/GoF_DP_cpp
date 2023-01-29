#include <iostream>
using namespace std;

// 규칙 : 모든 카메라는 아래 클래스로부터 파생되어야 한다.
//       모든 카메라는 아래 인터페이스를 구현해야 한다.

//C++에서 interface 키워드가 없어서 아래처럼 대체해서 사용할 경우도 있음
//#define interface struct

struct ICamera
{
    virtual void take() = 0;
    virtual ~ICamera() {}
};

// 카메라가 없어도 카메라를 사용하는 코드를 만들수 있다.
class People
{
public:
    void useCamera( ICamera* p ) { p->take(); }
};

class Camera : public ICamera
{
public:
    void take() { cout << "take picture" << endl;}
};

class HDCamera  : public ICamera
{
public:
    void take() { cout << "take HD picture" << endl;}
};

class UHDCamera  : public ICamera
{
public:
    void take() { cout << "take UHD picture" << endl;}
};

int main()
{
    People p;
    Camera c;
    p.useCamera(&c);

    HDCamera hc;
    p.useCamera(&hc);

    UHDCamera uhc;
    p.useCamera(&uhc);
}