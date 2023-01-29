class Animal
{
    // 생성자를 protected에 만드는 이유
    // 자기 자신은 객체로 만들 수 없지만, 파생 클래스의 객체는 만들 수 있게 하도록 함
protected:
    Animal() {}
};

class Dog
{
public:
    // 생성자의 정확한 호출 순서
    // Dog의 생성자가 먼저 호출된다
    // Dog의 생성자 안에서 기반 클래스인 Animal의 생성자를 호출한다
    // Dog() : Animal() {}
    Dog() {} 
};

int main()
{
    // Animal a; // Error
    Dog d;
    return 0;
}

