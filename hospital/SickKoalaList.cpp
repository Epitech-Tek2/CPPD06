/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD06-clement.muth
** File description:
** SickKoalaList
*/

#include <iostream>
#include <string>
#include <fstream>
#include "SickKoalaList.hpp"

SickKoalaList::SickKoalaList(SickKoala *koala)
{
    this->koala = koala;
    this->next = NULL;
}

SickKoalaList::~SickKoalaList()
{

}

void SickKoalaList::append(SickKoalaList *next)
{
    if (this->isEnd()) this->next = next;
    else this->next->append(next);
}

bool SickKoalaList::isEnd()
{
    return ((!this->next) ? true : false);
}

SickKoala *SickKoalaList::getFromName(std::string name)
{
    return (
        (this->koala && this->koala->getName() == name) ?
            this->koala :
            (this->next) ?
                this->next->getFromName(name) :
        NULL
    );
}

SickKoala * SickKoalaList::getItem()
{
    return (this->koala);
}

SickKoalaList *SickKoalaList::remove(SickKoalaList *remove)
{
    cur = this;
    prev = NULL;
    for (; cur; prev = cur, cur = cur->next) {
        if (remove == cur) {
            if (prev) {
                prev->next = cur->next;
                cur->next = NULL;
                return (this);
            } else {
                prev = cur->next;
                cur->next = NULL;
                return (prev);
            }
        }
    }
    return (this);
}

SickKoalaList *SickKoalaList::removeFromName(std::string name)
{
    cur = this;
    prev = NULL;
    while (cur) {
        if (cur && cur->koala && cur->koala->getName() == name) {
            if (prev) {
                prev->next = cur->next;
                return (this);
            } else {
                prev = cur->next;
                return (prev);
            }
            cur->next = NULL;
        }
        prev = cur;
        cur = cur->next;
    }
    return (NULL);
}

void SickKoalaList::dump()
{
    SickKoalaList *cur = this;

    std::cout << "Patients: ";
    while (cur) {
        (cur->koala) ? std::cout << cur->koala->getName() : std::cout << "[nullptr]";
        (cur->next) ? std::cout << ", " : std::cout << "." << std::endl;
        cur = cur->next;
    }
}

SickKoala *SickKoalaList::getContent()
{
    return (this->getItem());
}

SickKoalaList *SickKoalaList::getNext()
{
    return (this->next);
}