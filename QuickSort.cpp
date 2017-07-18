#include <exception>
#include <iostream>
#include <random>

using namespace std;

int RandomInRange(int min, int max)
{
    std::random_device rd;
    return rd() % (max - min + 1) + min;
    
    //std::default_random_engine generator;
    //std::uniform_int_distribution<int> dis(min, max);
    //return dis(generator);
}

int Partition(int data[], int length, int start, int end)
{
    if (data == nullptr || length <= 0 || start < 0 || end >= length)
    {
        throw new std::runtime_error("Invaild parameters.");
    }

    int index = RandomInRange(start, end);
    std::cout << "Random index: " << index << std::endl;
    std::swap(data[index], data[end]);
    
    // small指向比key小的数的队列的末尾
    int small = start - 1;
    for (index = start; index < end; ++index)
    {
        if (data[index] < data[end])
        {
            ++small;
            if (small != index)
            {
                std::swap(data[index], data[small]);
            }
        }
    }
    ++small;
    std::swap(data[small], data[end]);
    return small;
}

void QuickSort(int data[], int length, int start, int end)
{
    if (start == end)
        return;
    int index = Partition(data, length, start, end);
    if (index > start)
    {
        QuickSort(data, length, start, index - 1);
    }
    if (index < end)
    {
        QuickSort(data, length, index + 1, end);
    }
}

static void TestUnit()
{
    int data[] = {2,6,1,3,2,67,12,43,98,21};
    
    std::cout << "Origin data: \n";
    for (auto i : data)
        std::cout << i << "\t";
    std::cout << std::endl;
    
    QuickSort(data, sizeof(data) / sizeof(int), 0, sizeof(data) / sizeof(int) - 1);
    
    std::cout << "Sorted data: \n";
    for (auto i : data)
        std::cout << i << "\t";
    std::cout << std::endl;
    
    
}

int main()
{
    TestUnit();
    getchar();
    return 0;
}