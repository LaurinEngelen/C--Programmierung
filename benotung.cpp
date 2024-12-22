#include "benotung.h"
#include <stdexcept>
#include <array>
#include <stdio.h>
#include <string>

const benotung benotung::BESTE = benotung(10);

const benotung benotung::SCHLECHTESTE = benotung(50);

namespace {
    std::array <int,11> pNote = {10, 13, 17, 20, 23, 27, 30, 33, 37, 40, 50};
}

benotung::benotung (int n)
: note(n)
{
    for (int note: pNote){
        if(n == note){
            return;
        }
    }
    throw std::invalid_argument("unzulaessige Note: " + std::to_string(n));
}


int benotung::int_value() const {return note;}

bool benotung::ist_bestanden() const {return note <= 40;}

bool operator==(const benotung& b1, const benotung& b2){
    return &b1 == &b2 || b1.note == b2.note;
}

