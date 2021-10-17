/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD06-clement.muth
** File description:
** KoalaDoctorList
*/

#include <iostream>
#include <string>
#include <fstream>
#include "KoalaDoctorList.hpp"

KoalaDoctorList::KoalaDoctorList(KoalaDoctor *doctor)
{
    this->doctor = doctor;
    this->next = NULL;
}

KoalaDoctorList::~KoalaDoctorList()
{

}

void KoalaDoctorList::append(KoalaDoctorList *next)
{
    if (this->isEnd()) this->next = next;
    else this->next->append(next);
}

bool KoalaDoctorList::isEnd()
{
    return ((!this->next) ? true : false);
}

KoalaDoctor *KoalaDoctorList::getFromName(std::string name)
{
    return (
        (this->doctor && this->doctor->getName() == name) ?
            this->doctor :
            (this->next) ?
                this->next->getFromName(name) :
        NULL
    );
}

KoalaDoctor * KoalaDoctorList::getItem()
{
    return (this->doctor);
}

KoalaDoctorList *KoalaDoctorList::remove(KoalaDoctorList *remove)
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

KoalaDoctorList *KoalaDoctorList::removeFromName(std::string name)
{
    cur = this;
    prev = NULL;
    while (cur) {
        if (cur && cur->doctor && cur->doctor->getName() == name) {
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

void KoalaDoctorList::dump()
{
    KoalaDoctorList *cur = this;

    std::cout << "Doctors: ";
    while (cur) {
        (cur->doctor) ? std::cout << cur->doctor->getName() : std::cout << "[nullptr]";
        (cur->next) ? std::cout << ", " : std::cout << "." << std::endl;
        cur = cur->next;
    }
}

KoalaDoctor *KoalaDoctorList::getContent()
{
    return (this->getItem());
}

KoalaDoctorList *KoalaDoctorList::getNext()
{
    return (this->next);
}