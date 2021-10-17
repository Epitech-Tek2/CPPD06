/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD06-clement.muth
** File description:
** KoalaDoctor
*/


#include <iostream>
#include <string>
#include <fstream>
#include "KoalaDoctor.hpp"

KoalaDoctor::KoalaDoctor(std::string name)
{
    this->name = name;
    this->c_out(std::string("I'm Dr." + name + "! How do you kreog?"));
}

KoalaDoctor::~KoalaDoctor()
{

}

std::string KoalaDoctor::getName()
{
    return (this->name);
}

void KoalaDoctor::c_out(std::string message)
{
    if (message.empty())
        return;
    std::cout << "Dr." + this->name + ": " + message << std::endl;
}

void KoalaDoctor::diagnose(SickKoala *koala)
{
    if (!koala)
        return;
    this->c_out(std::string("So what's goerking you Mr." + koala->getName() + "?"));
    koala->poke();
    diagnoseReport.filename = koala->getName() + ".report";
    diagnoseReport.report = std::fstream(diagnoseReport.filename.data(), std::fstream::out | std::fstream::trunc);
    if (diagnoseReport.report) {
        diagnoseReport.drug = diagnoseReport.drugs[random() % 5].data();
        diagnoseReport.report.write(diagnoseReport.drug.data(), diagnoseReport.drug.length());
        diagnoseReport.report.close();
    }
}

void KoalaDoctor::timeCheck()
{
    this->c_out((this->hasWorked) ? "Time to go home to my eucalyptus forest!"
    : "Time to get to work!");
    this->hasWorked = !this->hasWorked;
}