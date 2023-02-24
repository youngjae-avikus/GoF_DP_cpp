#include <iostream>

// 변하는 것을 분리하는 방법

template<typename T> class List
{
public:
    void push_front(const T& a)
    {
        // Lock()
            // ..
        // Unlock();
    }
};

List<int> s; // 멀티 스레드에 안전하지 않다

// mutex에 대한 선택을 줘야 한다

int main()
{
    s.push_front(10);

    return 0;
}