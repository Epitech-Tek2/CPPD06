/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD06-clement.muth
** File description:
** KoalaDoctor
*/

#ifndef KOALADOCTOR_HPP_
#define KOALADOCTOR_HPP_

#include <iostream>
#include <string>
#include <fstream>
#include "SickKoala.hpp"

class Diagnose
{
    public:
        std::string filename;
        std::fstream report;
        std::string drugs[5] = {
            "Mars", "Kinder", "Crunch", "Maroilles", "Eurcalyptus leaf"
        };
        std::string drug;
        std::string simple_drug;
    private:
};

class KoalaDoctor {
    public:
        KoalaDoctor(std::string name);
        ~KoalaDoctor();

        std::string getName();
        void c_out(std::string message);
        void diagnose(SickKoala *koala);
        void timeCheck();

    private:
        std::string name;
        bool hasWorked = false;
        Diagnose diagnoseReport;
};

#endif /* !KOALADOCTOR_HPP_ */