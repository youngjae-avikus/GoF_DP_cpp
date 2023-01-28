#include <iostream>
#include <string>

using Application = std::string;

/// 빌더 패턴 의도
/// 복잡한 객체를 생성하는 방법과 표현하는 방법을 정의하는 클래스를 별도로 분리
/// 서로 다른 표현이라도 이를 생성할 수 있는 동일한 구축 공정을 제공할 수 있어야 한다

class IBuilder
{
public:
    virtual void makeName(std::string) = 0;
    virtual void makePhone(std::string) = 0;
    virtual void makeAddress(std::string) = 0;
    virtual Application getResult() = 0;
    virtual ~IBuilder() {}
};

class XMLBuilder : public IBuilder
{
    Application app;
public:
    virtual void makeName(std::string name)  
    {
        app += "<NAME>" + name + "</NAME>\n";
    }
    virtual void makePhone(std::string phone)
    {
        app += "<PHONE>" + phone + "</PHONE>\n";
    }
    virtual void makeAddress(std::string address)
    {
        app += "<ADDRESS>" + address + "</ADDRESS>\n";
    }
    virtual Application getResult()
    {
        return app;
    }
};

class TextBuilder : public IBuilder
{
    Application app;
public:
    virtual void makeName(std::string name)  
    {
        app += name + "\n";
    }
    virtual void makePhone(std::string phone)
    {
        app += phone + "\n";
    }
    virtual void makeAddress(std::string address)
    {
        app += address + "\n";
    }
    virtual Application getResult()
    {
        return app;
    }
};

// 지원서를 만드는 클래스
class Director
{
    std::string name = "홍길동";
    std::string phone = "010-xxxx-xxxx";
    std::string address = "서울시 서초구";
    IBuilder *builder;

public:
    void setBuilder(IBuilder* bd)
    {
        builder = bd;
    }

    Application construct()
    {
        builder->makeName(name);
        builder->makePhone(phone);
        builder->makeAddress(address);
        
        return builder->getResult();
    }
};

int main()
{
    Director d;
    XMLBuilder xbd;
    d.setBuilder(&xbd);
    std::cout <<d.construct();

    TextBuilder tbd;
    d.setBuilder(&tbd);
    std::cout <<d.construct();
    
    return 0;
}