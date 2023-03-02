#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

class CompareStrategy
{
public:
    virtual bool operator()(const int &a, const int &b) const = 0;
};

class AscendingCompare : public CompareStrategy
{
public:
    bool operator()(const int &a, const int &b) const
    {
        return a < b;
    }
};

class DescendingCompare : public CompareStrategy
{
public:
    bool operator()(const int &a, const int &b) const
    {
        return a > b;
    }
};

class ArgSortContext
{
private:
    CompareStrategy *strategy_;

public:
    explicit ArgSortContext(CompareStrategy *strategy) : strategy_(strategy) {}

    void set_strategy(CompareStrategy *strategy)
    {
        strategy_ = strategy;
    }

    std::vector<int> operator()(const std::vector<int> &vec) const
    {
        std::vector<int> indices(vec.size());
        std::iota(indices.begin(), indices.end(), 0);
        std::sort(indices.begin(), indices.end(), [&](int a, int b) {
            return (*strategy_)(vec[a], vec[b]);
        });

        return indices;
    }
};

int main()
{
    // Create a vector of integers
    std::vector<int> vec {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};

    ArgSortContext ctx(new AscendingCompare());

    std::vector<int> indices = ctx(vec);

    for(const auto &idx : indices) {
        std::cout << vec[idx] << " ";
    }
    std::cout << std::endl;

    ctx.set_strategy(new DescendingCompare());

    indices = ctx(vec);

    for(const auto &idx : indices) {
        std::cout << vec[idx] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}