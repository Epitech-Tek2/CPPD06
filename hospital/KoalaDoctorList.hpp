/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD06-clement.muth
** File description:
** KoalaDoctor
*/

#ifndef KOALADOCTORLIST_HPP_
#define KOALADOCTORLIST_HPP_

#include <iostream>
#include <string>
#include <fstream>
#include "KoalaDoctor.hpp"

class KoalaDoctorList {
    public:
        KoalaDoctorList(KoalaDoctor *doctor);
        ~KoalaDoctorList();

        bool isEnd();
        KoalaDoctor *getFromName(std::string name);
        KoalaDoctor *getItem();
        KoalaDoctorList *remove(KoalaDoctorList *remove);
        KoalaDoctorList *removeFromName(std::string name);
        KoalaDoctor *getContent();
        KoalaDoctorList *getNext();
        void append(KoalaDoctorList *next);
        void dump();

    private:
        KoalaDoctor *doctor;
        KoalaDoctorList *next;
        KoalaDoctorList *cur;
        KoalaDoctorList *prev;
        bool prevExist;
};

#endif /* !KOALADOCTORLIST_HPP_ */