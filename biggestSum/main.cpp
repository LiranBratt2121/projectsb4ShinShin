#include <iostream>
#include <vector>
#include <stdint.h>

class INode
{
public:
    INode(int val, INode &next) : m_val(val), m_next(next) {}

    int m_val;
    INode &m_next;
};

int biggest_sum(std::vector<int> &arr)
{
    int sum = 0;
    int max = INT32_MIN;
    int zero_counter = 2;

    for (int val : arr){
        if (val == 0){
            zero_counter--;

            if (zero_counter == 0){
                if (sum > max){
                    max = sum;
                }

                sum = 0;
                zero_counter = 2;
            }

        }else {
            sum += val;
        }
    }

    return max;
}

int main() {
    std::vector<int> arr = {33, 0, 5, 4, 0, 17, 0, 4, 10, 0, 5, 14};

    int result = biggest_sum(arr);

    std::cout << "Biggest sum is: " << result << std::endl;
}