#include <iostream>

// Replace space in char array to "%20"
void replaceSpace(char string[], int length)
{
    if (!string || length <= 0)
        return;

    int originalLength = 0;
    int blankCount = 0;
    // scan once to get spaces count and extended string length
    for (int i = 0; i < length; ++i)
    {
        ++originalLength;
        if (string[i] == '\0')
            break;
        if (string[i] == ' ')
            ++blankCount;
    }
    if (blankCount == 0)
        return;
    
    int extendedLength = originalLength + 2 * blankCount;
    if (extendedLength > length)
        return;
    
    // point to original char array last character location
    char* p1 = string + originalLength - 1;
    // point to extended char array last character location 
    char* p2 = string + extendedLength - 1;

    while (p1 && p1 != p2)
    {
        if (*p1 != ' ')
        {
            // copy the item if it is not a space
            *p2 = *p1;
        }
        else
        {
            *p2 = '0';
            --p2;
            *p2 = '2';
            --p2;
            *p2 = '%';
        }
        --p1;
        --p2;
    }
}

int main()
{
    char string1[50] = "We are happy.";
    char string2[50] = "We  are happy.  ";
    char string3[50] = " Weare h a pp y .";
    replaceSpace(string1, 50);
    replaceSpace(string2, 50);
    replaceSpace(string3, 50);
    std::cout << string1 << std::endl;
    std::cout << string2 << std::endl;
    std::cout << string3 << std::endl;
}