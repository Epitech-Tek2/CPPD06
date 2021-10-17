/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD06-clement.muth
** File description:
** KoalaNurse
*/

#include "KoalaNurse.hpp"

KoalaNurse::KoalaNurse(int id)
{
    this->id = id;
    this->hasWorked = false;
}

KoalaNurse::~KoalaNurse()
{
    this->c_out("Finally some rest!");
}

int KoalaNurse::getID()
{
    return (this->id);
}

void KoalaNurse::c_out(std::string message)
{
    if (message.empty())
        return;
    std::cout << "Nurse " << this->id << ": " + message << std::endl;
}

void KoalaNurse::giveDrug(std::string drug, SickKoala *koala)
{
    if (!koala) return;
    koala->takeDrug(drug);
}

std::string KoalaNurse::readReport(std::string report)
{
    POS = report.find(".report");
    FILE = std::fstream(report.data(), std::ios::in);
    if ((POS != (int)std::string::npos &&
    !report.substr(POS).compare(".report") && FILE.is_open())) {
        BUF[FILE.readsome(BUF, 100)] = '\0';
        DRUG = BUF;
        KO = report.substr(0, POS);
        this->c_out(std::string("Kreog! Mr." + KO + " needs a " + DRUG +
        "!"));
    }
    FILE.close();
    return (DRUG);
}

void KoalaNurse::timeCheck()
{
    this->c_out((this->hasWorked) ? "Time to go home to my eucalyptus forest!"
    : "Time to get to work!");
    this->hasWorked = !this->hasWorked;
}