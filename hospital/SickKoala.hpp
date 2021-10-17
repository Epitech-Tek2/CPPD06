/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD06-clement.muth
** File description:
** SickKoala
*/

#ifndef SICKKOALA_HPP_
#define SICKKOALA_HPP_

#include <string>

class SickKoala
{
    public:
        SickKoala(std::string name);
        ~SickKoala();

        bool takeDrug(std::string drug);
        std::string getName();
        void c_out(std::string message);
        void overDrive(std::string message);
        void poke();

    private:
        std::string name;
};

#endif /* !SICKKOALA_HPP_ */