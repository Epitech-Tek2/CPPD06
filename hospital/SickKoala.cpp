/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD06-clement.muth
** File description:
** SickKoala
*/

#include <iostream>
#include <string>
#include <fstream>
#include "SickKoala.hpp"

SickKoala::SickKoala(std::string name)
{
    this->name = name;
}

SickKoala::~SickKoala()
{
    std::cout << "Mr." + this->getName() + ": Kreooogg!! I'm cuuuured!" << std::endl;
}

std::string SickKoala::getName()
{
    return (this->name);
}

void SickKoala::c_out(std::string message)
{
    if (message.empty())
        return;
    std::cout << "Mr." + this->name + ": " + message << std::endl;
}

void SickKoala::poke()
{
    SickKoala::c_out("Gooeeeeerrk!!");
}

bool SickKoala::takeDrug(std::string drug)
{
    if (drug.compare("Mars") == 0 || drug.compare("Kinder") == 0) {
        this->c_out(drug.compare("Mars") == 0 ?
            "Mars, and it kreogs!" :
            "There is a toy inside!"
        );
        return (true);
    }
    this->c_out("Goerkreog!");
    return (false);
}

void SickKoala::overDrive(std::string message)
{
    for (int i = 0; (i = message.find("Kreog!")) != (int)std::string::npos;)
        message.replace(i, 6, "1337! ", 0, 5);
    this->c_out(message);
}