#include <iostream>
#include <string>

using Application = std::string;

// 지원서를 만드는 클래스
class Director
{
    std::string name = "홍길동";
    std::string phone = "010-xxxx-xxxx";
    std::string address = "서울시 서초구";

public:
    Application construct()
    {
        Application app;
        app += name + "\n";
        app += phone + "\n";
        app += address + "\n";
        return app;
    }

    // 만일 지원서의 내용은 같지만, Form을 다르게 요구하는 경우 (예를 들어 txt, xml, json 형태의 포맷들)
    // 따로 만들기는 했지만, 안에 내용과 순서는 같다
    // 생성하는 부분과 표현하는 부분을 서로 분리해서 가져간다
    
    Application XMLconstruct()
    {
        Application app;
        app += "<NAME>" + name + "</NAME>\n";
        app += "<PHONE>" + phone + "</PHONE>\n";
        app += "<ADDRESS>" + address + "</ADDRESS>\n";
        return app;
    }
};

int main()
{
    Director d;
    Application app = d.construct();
    std::cout << app << "\n";

    app = d.XMLconstruct();
    std::cout << app << "\n";
    return 0;
}