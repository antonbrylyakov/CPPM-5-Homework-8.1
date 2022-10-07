#include <iostream>
#include "BadLength.h"
#include <windows.h>

int function(std::string& str, int forbidden_length)
{
    const int length = str.length();
    if (length != forbidden_length)
    {
        return length;
    }

    throw BadLength();
}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);

    int forbiddenLength;
    std::string str;
    std::cout << "Введите запретную длину:";
    std::cin >> forbiddenLength;
    try
    {
        while (true)
        {
            std::cout << "Введите слово: ";
            std::cin >> str;
            std::cout << "Длина слова \"" << str << "\" равна " << function(str, forbiddenLength) << std::endl;
        }
    }
    catch (BadLength&)
    {
        std::cout << "Вы ввели запретную длину. До свидания!" << std::endl;
    }
    catch (...)
    {
        std::cout << "Непредвиденная ошибка!" << std::endl;
    }
}

