#include <iostream>
#include <cstring>

/// abfactory_01.cpp의 문제점은 매번 버튼,편집창을 만들때마다 분기문을 통해 검사해서 만들어야 한다는 점이다
/// 따라서 Factory를 설계해보도록 한다

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

class IFactory 
{
public:
    virtual IButton* CreateButton() = 0;
    virtual IEdit* CreateEdit() = 0;
    virtual ~IFactory() {}
};

class WinFactory : public IFactory
{
    IButton *CreateButton() { return new WinButton; }
    IEdit *CreateEdit() { return new WinEdit; }
    
};

class GTKFactory : public IFactory
{
    IButton *CreateButton() { return new GTKButton; }
    IEdit *CreateEdit() { return new GTKEdit; }
};


int main(int argc, char **argv)
{
    // Factory도 기반이 되는 Factorty 클래스가 있어야 함
    // 이를 추상 Factory라고 함
    IFactory* pFactory;
    if (std::strcmp(argv[1], "windows") == 0) {
        pFactory = new WinFactory;
    }
    else if (std::strcmp(argv[1], "gtk") == 0) {
        pFactory = new GTKFactory;
    }
    else {
        std::cerr << "param error\n";
        return -1;
    }

    IButton *iBtn = pFactory->CreateButton();
    IEdit *iEdit = pFactory->CreateEdit();
    
    iBtn->Draw();
    iEdit->Draw();

    return 0;
}