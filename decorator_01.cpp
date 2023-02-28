// 구성에 의한 기능 추가
/// 클래스가 아닌 객체에 기능 추가
/// 컴파일 시간이 아닌 실행시간에 기능 추가

// 상속에 의한 기능 추가
/// 클래스를 통한 기능 추가 대상
/// 정적으로만 추가가 가능해서 유연성이 떨어짐

#include <iostream>

class SpaceCraft
{
    int color;
    int speed;

public:
    void Fire()
    {
        std::cout << "Space Craft : -----------------\n";
    }
};

// class LeftMissile : public SpaceCraft
// {
// public:
//     void Fire()
//     {
//         SpaceCraft::Fire();
//         std::cout << "Left Missile : -----------------\n";
//     }
// };

class LeftMissile
{
    SpaceCraft *sc;

public:
    LeftMissile(SpaceCraft *p) : sc(p)
    {
    }

    void Fire() {
        sc->Fire();
        std::cout << "Left Missile : -----------------\n";
    }
};

int main()
{
    SpaceCraft sc;
    sc.Fire();

    LeftMissile lm(&sc);
    lm.Fire();
    return 0;
}
