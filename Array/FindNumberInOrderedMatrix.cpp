#include <iostream>

// Find whether the given number is in ordered matrix, right greater than left, bottom greater than 
bool find(int* matrix, int rows, int columns, int number)
{
    if (matrix && rows > 0 && columns > 0)
    {
        // Choose top right(or bottom left) (1 side greater and 1 side less)
        int row = 0, column = columns - 1;
        while (row < rows && column >= 0)
        {
            int currentNumber = matrix[row * columns + column];
            if (number > currentNumber)
                ++row;
            else if (number < currentNumber)
                --column;
            else
                return true;
        }
        return false;
    }
    return false;
}

int main()
{
    int matrix[16] = { 1, 2, 8, 9, 2, 4, 9, 12, 4, 7, 10, 13, 6, 8, 11, 15 };
    bool isFound4 = find(matrix, 4, 4, 4);
    bool isFound5 = find(matrix, 4, 4, 5);
    bool isFound14 = find(matrix, 4, 4, 14);
    bool isFound15 = find(matrix, 4, 4, 15);
    std::cout << "isFound4: " << isFound4 << std::endl;
    std::cout << "isFound5: " << isFound5 << std::endl;
    std::cout << "isFound14: " << isFound14 << std::endl;
    std::cout << "isFound15: " << isFound15 << std::endl;
}