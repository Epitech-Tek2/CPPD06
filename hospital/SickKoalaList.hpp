/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD06-clement.muth
** File description:
** SickKoala
*/

#ifndef SICKKOALALIST_HPP_
#define SICKKOALALIST_HPP_

#include <iostream>
#include <string>
#include <fstream>
#include "SickKoala.hpp"

class SickKoalaList
{
    public:
        SickKoalaList(SickKoala *koala);
        ~SickKoalaList();

        bool isEnd();
        SickKoala *getFromName(std::string name);
        SickKoala *getItem();
        SickKoalaList *remove(SickKoalaList *remove);
        SickKoalaList *removeFromName(std::string name);
        SickKoala *getContent();
        SickKoalaList *getNext();
        void append(SickKoalaList *next);
        void dump();

    private:
        SickKoala *koala;
        SickKoalaList *next;
        SickKoalaList *cur;
        SickKoalaList *prev;
        bool prevExist;
};

#endif /* !SICKKOALALIST_HPP_ */