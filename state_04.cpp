#include <iostream>
using namespace std;

struct IState
{
    virtual void runImpl() = 0;
    virtual void attackImpl() = 0;
    virtual ~IState() {}
};

class Character
{
    int gold = 0;
    int item = 0;
    IState *state;

public:
    void changeState(IState *p) { state = p; }
    void run()
    {
        state->runImpl();
    }
    void attack()
    {
        state->attackImpl();
    }
};

class PowerItemState : public IState
{
public:
    virtual void runImpl() { cout << "fast run" << endl; }
    virtual void attackImpl() { cout << "attack" << endl; }
};

class NormalItemState : public IState
{
public:
    virtual void runImpl() { cout << "run" << endl; }
    virtual void attackImpl() { cout << "power attack" << endl; }
};

int main()
{
    Character p;
    PowerItemState pi;
    NormalItemState ni;
    p.changeState(&ni);
    p.run();
    p.attack();
    
    p.changeState(&pi);
    p.run();
    p.attack();
}