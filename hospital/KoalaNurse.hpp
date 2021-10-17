/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD06-clement.muth
** File description:
** KoalaNurse
*/

#ifndef KOALANURSE_HPP_
#define KOALANURSE_HPP_

#include <iostream>
#include <string>
#include <fstream>
#include "SickKoala.hpp"

#define DRUG this->report.drug
#define POS this->report.position
#define FILE this->report.file
#define BUF this->report.buffer
#define KO this->report.koala

class Report
{
    public:
        int position;
        char buffer[100];
        std::fstream file;
        std::string koala = "";
        std::string drug = "";
    private:
};

class KoalaNurse {
    public:
        KoalaNurse(int id);
        ~KoalaNurse();

        int getID();
        std::string getName();
        std::string readReport(std::string report);
        void c_out(std::string message);
        void giveDrug(std::string drug, SickKoala *Koala);
        void timeCheck();

    private:
        bool hasWorked;
        int id;
        Report report;
};

#endif /* !KOALANURSE_HPP_ */