#include <iostream>

/*
Factory Method 의도
- 객체를 생성하기 위해 인터페이스를 정의하지만, 어떤 클래스의 인스턴스를 생성할지에 대한 결정은 "서브" 클래스가 한다
- Factory Method 패턴에서는 클래스의 인스턴스를 만드는 시점을 "서브" 클래스로 미룬다
- Template method와 유사한 형태다
*/

class IEdit
{
public:
    virtual void Draw() = 0;
    virtual ~IEdit() {}
};

class IButton
{
public:
    virtual void Draw() = 0;
    virtual ~IButton() {}
};

class WinButton: public IButton
{
public:
    virtual void Draw() {std::cout << "Draw Window Button" << std::endl;}
};

class GTKButton: public IButton
{
public:
    virtual void Draw() {std::cout << "Draw GTK Button" << std::endl;}
};

class WinEdit: public IEdit
{
public:
    virtual void Draw() {std::cout << "Draw Window Edit" << std::endl;}
};

class GTKEdit: public IEdit
{
public:
    virtual void Draw() {std::cout << "Draw GTK Edit" << std::endl;}
};


class BaseDialog
{
public:
    void Init() {
        IButton *pBtn = CreateButton();
        IEdit *pEdit = CreateEdit();
        
        pBtn->Draw();
        pEdit->Draw();
    }

    // 클래스의 인스턴스를 만드는 시점을 "서브" 클래스로 미룬다
    virtual IButton* CreateButton() = 0;
    virtual IEdit* CreateEdit() = 0;
};

// Diaglog가 있다고 가정
// WinDialog, GTKDialog의 Init 함수가 겹치기 때문에 이를 기반 클래스에서 구현하도록 한다
class WinDialog : public BaseDialog
{
public:
    virtual IButton* CreateButton() {return new WinButton;}
    virtual IEdit* CreateEdit() {return new WinEdit;}
};

class GTKDialog : public BaseDialog
{
public:
    virtual IButton* CreateButton() {return new GTKButton;}
    virtual IEdit* CreateEdit() {return new GTKEdit;}
};

int main()
{
    WinDialog wd;
    GTKDialog gd;

    wd.Init();
    gd.Init();

    return 0;
}