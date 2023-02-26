#include <iostream>
using namespace std;

class Character
{
    int gold = 0;
    int item = 0;

public:
    void run()
    {
        runImpl();   
    }
    void attack()
    {
        attackImpl();
    }
    virtual void runImpl() { cout << "Base" << endl;}
    virtual void attackImpl() {}

    virtual ~Character() {}
};


class PowerItemCharacter : public Character
{
public:
    virtual void runImpl() { cout << "fast run" << endl;}
    virtual void attackImpl() { cout << "attack" << endl;}
};

class NormalCharacter : public Character
{
public:
    virtual void runImpl() { cout << "run" << endl;}
    virtual void attackImpl() { cout << "power attack" << endl;}
};

int main()
{
    Character *p = new NormalCharacter;
    p->run();
    p->attack();

    // 아이템 획득 시
    // 이 코드의 문제는 내부 속성만이 아닌 전체 캐릭터가 바뀐다는 것이다
    // 캐릭터가 가지고 있는 돈, 체력 등이 새로 바뀌어버린다
    p = new PowerItemCharacter;
    p->run();
    p->attack();
}