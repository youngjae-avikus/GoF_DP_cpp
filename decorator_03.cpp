// 구성에 의한 기능 추가
/// 클래스가 아닌 객체에 기능 추가
/// 컴파일 시간이 아닌 실행시간에 기능 추가

// 상속에 의한 기능 추가
/// 클래스를 통한 기능 추가 대상
/// 정적으로만 추가가 가능해서 유연성이 떨어짐

/*
/// 아래 변수 선언과 객체 생성에 대한 부분이 공통된다
class LeftMissile : public Component
{
    Component *sc;

public:
    LeftMissile(Component *p) : sc(p)
    {
    }

////////////////////////////////////////
class RightMissile : public Component
{
    Component *sc;

public:
    RightMissile(Component *p) : sc(p)
    {
    }

*/

#include <iostream>

struct Component
{
    virtual void Fire() = 0;
    virtual ~Component() {}
};

class SpaceCraft : public Component
{
    int color;
    int speed;

public:
    void Fire()
    {
        std::cout << "Space Craft : -----------------\n";
    }
};

// 객체 구성에 대한 Decorator
class IDecorator : public Component
{
    Component *sc;

public:
    IDecorator(Component *p) : sc(p)
    {
    }
    void Fire() {
        sc->Fire();
    }
};

class LeftMissile : public IDecorator
{
public:
    LeftMissile(Component *p) : IDecorator(p)
    {
    }

    void Fire() {
        IDecorator::Fire();
        std::cout << "Left Missile : -----------------\n";
    }
};

class RightMissile : public IDecorator
{
public:
    RightMissile(Component *p) : IDecorator(p)
    {
    }

    void Fire() {
        IDecorator::Fire();
        std::cout << "Right Missile : -----------------\n";
    }
};

int main()
{
    SpaceCraft sc;
    sc.Fire();

    LeftMissile lm(&sc);
    lm.Fire();

    RightMissile rm(&lm);
    rm.Fire();

    return 0;
}
