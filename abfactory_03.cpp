#include <iostream>
#include <cstring>

/// abfactory_02.cpp에서 Factory 객체를 Singleton으로 설계해보려고 함
/// 추상팩토리 자체는 pure function을 포함하기 때문에 설게가 어렵다
/// 상속받은 자식 팩토리만 설계 가능 => 컴파일 후 동작은 하는데 맞는 방법인지는 확인해봐야 함

#define MAKE_SINGLETON(classname)   \
    classname() {}  \
    classname(const classname& ) = delete;  \
    void operator=(const classname& ) = delete; \
public: \
    static classname& getInstance() \
    {   \
        static classname instance;  \
        return instance;    \
    } 

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
    MAKE_SINGLETON(WinFactory)

    IButton *CreateButton() { return new WinButton; }
    IEdit *CreateEdit() { return new WinEdit; }
    
};

class GTKFactory : public IFactory
{
    MAKE_SINGLETON(GTKFactory)
    
    IButton *CreateButton() { return new GTKButton; }
    IEdit *CreateEdit() { return new GTKEdit; }
};


int main(int argc, char **argv)
{
    // Factory도 기반이 되는 Factorty 클래스가 있어야 함
    // 이를 추상 Factory라고 함
    IFactory* pFactory;
    if (std::strcmp(argv[1], "windows") == 0) {
        pFactory = &WinFactory::getInstance();
    }
    else if (std::strcmp(argv[1], "gtk") == 0) {
        pFactory = &GTKFactory::getInstance();
    }
    else {
        std::cerr << "param error\n";
        return -1;
    }

    IButton *iBtn = pFactory->CreateButton();
    IEdit *iEdit = pFactory->CreateEdit();
    
    IButton *iBtn2 = pFactory->CreateButton();
    IEdit *iEdit2 = pFactory->CreateEdit();


    iBtn->Draw();
    iEdit->Draw();

    iBtn2->Draw();
    iEdit2->Draw();

    return 0;
}