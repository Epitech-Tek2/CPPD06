/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD06-clement.muth
** File description:
** KoalaNurseList
*/

#include <iostream>
#include <string>
#include <fstream>
#include "KoalaNurseList.hpp"

KoalaNurseList::KoalaNurseList(KoalaNurse *nurse)
{
    this->nurse = nurse;
    this->next = NULL;
}

KoalaNurseList::~KoalaNurseList()
{

}

void KoalaNurseList::append(KoalaNurseList *next)
{
    if (this->isEnd()) this->next = next;
    else this->next->append(next);
}

bool KoalaNurseList::isEnd()
{
    return ((!this->next) ? true : false);
}

KoalaNurse *KoalaNurseList::getFromID(int id)
{
    return (
        (this->nurse && this->nurse->getID() == id) ?
            this->nurse :
            (this->next) ?
                this->next->getFromID(id) :
        NULL
    );
}

KoalaNurse *KoalaNurseList::getItem()
{
    return (this->nurse);
}

KoalaNurseList *KoalaNurseList::remove(KoalaNurseList *remove)
{
    cur = this;
    if (cur && !cur->next) return (this);
    prev = NULL;
    for (; cur; prev = cur, cur = cur->next) {
        if (remove == cur) {
            prevExist = (prev) ? true : false;
            prev->next = cur->next;
            cur->next = NULL;
            return ((prevExist) ? this : prev);
        }
    }
    return (NULL);
}

KoalaNurseList *KoalaNurseList::removeFromID(int id)
{
    cur = this;
    prev = NULL;
    while (cur) {
        if (cur && cur->nurse && cur->nurse->getID() == id) {
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

void KoalaNurseList::dump()
{
    KoalaNurseList *cur = this;

    std::cout << "Nurses: ";
    while (cur) {
        (cur->nurse) ? std::cout << "id" << cur->nurse->getID() : std::cout << "[nullptr]";
        (cur->next) ? std::cout << ", " : std::cout << "." << std::endl;
        cur = cur->next;
    }
}

KoalaNurse *KoalaNurseList::getContent()
{
    return (this->getItem());
}

KoalaNurseList *KoalaNurseList::getNext()
{
    return (this->next);
}