/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD06-clement.muth
** File description:
** main
*/

#include <iostream>
#include <string>
#include <iomanip>

class temp
{
    public:
        float tmp = 0;
        float cnv = 0;
        std::string unite;

        void print(temp temp)
        {
            std::cout.width(16);
            std::cout << std::right << std::fixed << std::setprecision(3) << temp.cnv;
            std::cout.width(16);
            std::cout << temp.unite << std::endl;
        }
        void celsius(temp *temp)
        {
            temp->cnv = temp->tmp * 9.0 / 5.0 + 32;
            temp->unite = "Fahrenheit";
            temp->print(*temp);
        }
        void fahrenheit(temp *temp)
        {
            temp->cnv = (temp->tmp - 32) * 5.0 / 9.0;
            temp->unite = "Celsius";
            temp->print(*temp);
        }
};

int tmp_cnv(void)
{
    temp temp;

    std::cin >> temp.tmp >> temp.unite;
    if (!temp.unite.compare("Celsius"))
        temp.celsius(&temp);
    else if (!temp.unite.compare("Fahrenheit"))
        temp.fahrenheit(&temp);
    return (0);
}

int main(void)
{
    return (tmp_cnv());
}