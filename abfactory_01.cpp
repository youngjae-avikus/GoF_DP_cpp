#include <iostream>
#include <cstring>

class IButton
{
public:
    virtual void Draw() = 0;
    virtual ~IButton() {}
};

class IEdit
{
public:
    virtual void Draw() = 0;
    virtual ~IEdit() {}
};

class WinButton : public IButton
{
public:
    void Draw() {std::cout << "Draw WinButton" << std::endl;}
};

class GTKButton : public IButton
{
public:
    void Draw() {std::cout << "Draw GTKButton" << std::endl;}
};

class WinEdit : public IEdit
{
public:
    void Draw() {std::cout << "Draw WinEdit" << std::endl;}
};

class GTKEdit : public IEdit
{
public:
    void Draw() {std::cout << "Draw GTKEdit" << std::endl;}
};

int main(int argc, char **argv)
{
    // style param에 객체 생성이 가능해야 한다
    // ===> 기반 클래스를 만들어서 다형성을 이용한다
    // WinButton *pBtn = new WinButton;
    // pBtn->Draw();
    IButton* pBtn;

    // 
    if (std::strcmp(argv[1], "windows") == 0) {
        pBtn = new WinButton;
    }
    else if (std::strcmp(argv[1], "gtk") == 0) {
        pBtn = new GTKButton;
    }
    else {
        std::cerr << "param error\n";
        return -1;
    }

    pBtn->Draw();

    return 0;
}