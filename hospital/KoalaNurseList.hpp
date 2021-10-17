/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD06-clement.muth
** File description:
** koalanurselist
*/

#ifndef KOALANURSELIST_HPP_
#define KOALANURSELIST_HPP_

#include <iostream>
#include <string>
#include <fstream>
#include "KoalaNurse.hpp"

class KoalaNurseList
{
    public:
        KoalaNurseList(KoalaNurse *koala);
        ~KoalaNurseList();

        void append(KoalaNurseList *next);
        bool isEnd();
        KoalaNurse *getFromID(int id);
        KoalaNurse *getItem();
        KoalaNurseList *remove(KoalaNurseList *remove);
        KoalaNurseList *removeFromID(int id);
        KoalaNurse *getContent();
        KoalaNurseList *getNext();
        void dump();

    private:
        KoalaNurse *nurse;
        KoalaNurseList *next;
        KoalaNurseList *cur;
        KoalaNurseList *prev;
        bool prevExist;
};

#endif /* !KOALANURSELIST_HPP_ */