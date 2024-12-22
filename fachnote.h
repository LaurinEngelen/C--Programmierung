#ifndef FACHNOTE_H
#define FACHNOTE_H

#include "benotung.h"
#include <stdexcept>
#include <string>


class fachnote {
 
public:

    std::string fach;
    benotung note;

    fachnote (const std::string& f, const benotung& b);

    fachnote(const fachnote&) = delete;
    fachnote(const fachnote&&) = delete;
    fachnote& operator=(const fachnote&) = delete;
    fachnote& operator=(fachnote&&) = delete;
};


#endif