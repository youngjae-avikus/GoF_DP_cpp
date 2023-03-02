#include <iostream>
#include <algorithm>
#include <vector>

template <typename T>
class SortableVector
{
    std::vector<T> data;

public:
    SortableVector(const std::vector<T> &v) : data(v) {}
    void sort() { std::sort(data.begin(), data.end()); }
    void print() const
    {
        for (const auto &d : data)
        {
            std::cout << d << " ";
        }
        std::cout << std::endl;
    }
};

template <typename T1, typename T2>
class SortableVector<std::pair<T1, T2>>
{
    std::vector<std::pair<T1, T2>> data;

public:
    SortableVector(std::vector<std::pair<T1, T2>> &v) : data(v) {}
    void sort() { std::sort(data.begin(), data.end()); }
    void print() const
    {
        for (const auto &d : data)
        {
            std::cout << "(" << d.first << ", " << d.second << ") ";
        }
        std::cout << std::endl;
    }
};

int main()
{
    std::vector<int> v1 = {3, 1, 4, 2};
    std::vector<double> v2 = {3.14, 1.41, 2.72};
    std::vector<std::pair<int, double>> v3 = {{3, 3.14}, {1, 1.41}, {4, 2.72}, {2, 0.0}};

    SortableVector<int> sv1(v1);
    sv1.sort();
    sv1.print();

    SortableVector<double> sv2(v2);
    sv2.sort();
    sv2.print();

    SortableVector<std::pair<int, double>> sv3(v3);
    sv3.sort();
    sv3.print();

    return 0;
}