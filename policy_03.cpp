
#include <iostream>

class MutexLock;
class NoLock;

template <typename T, typename LockModel = NoLock>
class List
{
    LockModel lm;

public:

    void push_front(const T &a)
    {
        lm.Lock();
        //  ...
        lm.UnLock();
    }
};
 
class MutexLock
{
public:
    inline void Lock() { std::cout << "MutexLock Lock!\n"; }
    inline void UnLock() { std::cout << "MutexLock UnLock!\n"; }
};

class NoLock
{
public:
    inline void Lock() { std::cout << "NoLock Lock!\n"; }
    inline void UnLock() { std::cout << "NoLock UnLock!\n"; }
};

List<int, MutexLock> s1;
List<int> s2;

int main()
{
    s1.push_front(10);
    s2.push_front(20);

    /*
    MutexLock Lock!
    MutexLock UnLock!
    NoLock Lock!
    NoLock UnLock!    
    */
    return 0;
}