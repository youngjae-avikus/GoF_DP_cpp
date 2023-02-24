#include <iostream>

// 변하는 것을 분리하는 방법
struct ISync
{
    virtual void Lock() = 0;
    virtual void UnLock() = 0;
    virtual ~ISync() {}
};

template <typename T>
class List
{
    ISync *pSync = 0;

public:
    void setISync(ISync *p) { pSync = p; }

    void push_front(const T &a)
    {
        if (pSync != 0)
            pSync->Lock();
        //  ...
        if (pSync != 0)
            pSync->UnLock();
    }
};

List<int> s; // 멀티 스레드에 안전하지 않다

// mutex에 대한 선택을 줘야 한다

class MutexLock : public ISync
{
public:
    virtual void Lock() {}
    virtual void UnLock() {}
};

int main()
{
    MutexLock m;
    s.setISync(&m);

    s.push_front(10);

    return 0;
}