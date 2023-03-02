#include <iostream>
#include <vector>

// Strategy interface
template <typename T>
class SortingStrategy
{
public:
    virtual void sort(std::vector<T> &v) = 0;
};

// Concrete strategy: QuickSort
template <typename T>
class QuickSort : public SortingStrategy<T>
{
public:
    virtual void sort(std::vector<T> &v)
    {
        // TODO: Implement QuickSort algorithm
        std::cout << "Sorting using QuickSort" << std::endl;
    }
};

// Concrete strategy: MergeSort
template <typename T>
class MergeSort : public SortingStrategy<T>
{
public:
    virtual void sort(std::vector<T> &v)
    {
        // TODO: Implement MergeSort algorithm
        std::cout << "Sorting using MergeSort" << std::endl;
    }
};

// Context class that uses the sorting strategy
template <typename T>
class Sorter
{
private:
    SortingStrategy<T> *strategy_;

public:
    Sorter(SortingStrategy<T> *strategy) : strategy_(strategy) {}

    void set_strategy(SortingStrategy<T> *strategy)
    {
        strategy_ = strategy;
    }

    void sort(std::vector<T> &v)
    {
        strategy_->sort(v);
    }
};

int main()
{
    // Create a vector of integers
    std::vector<int> v = {5, 4, 3, 2, 1};

    // Create sorting strategies
    SortingStrategy<int> *quick_sort = new QuickSort<int>();
    SortingStrategy<int> *merge_sort = new MergeSort<int>();

    // Create sorter objects that use the sorting strategies
    Sorter<int> quick_sorter(quick_sort);
    Sorter<int> merge_sorter(merge_sort);

    // Sort the vector using different strategies
    quick_sorter.sort(v);
    merge_sorter.sort(v);

    // Change the sorting strategy at runtime
    quick_sorter.set_strategy(merge_sort);
    quick_sorter.sort(v);

    // Clean up
    delete quick_sort;
    delete merge_sort;

    return 0;
}
