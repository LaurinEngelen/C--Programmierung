#ifndef BENOTTUN_H
#define BENOTTUN_H
#include <stdexcept>
#include <vector>
#include <stdio.h>


class benotung {

private:
    int note;
    
public:
    explicit benotung (int n);

    static const benotung BESTE;
    static const benotung SCHLECHTESTE;

    int int_value() const;
    bool ist_bestanden() const;

    friend bool operator==(const benotung &b1, const benotung &b2);
};

bool operator==(const benotung &b1, const benotung &b2);

#endif