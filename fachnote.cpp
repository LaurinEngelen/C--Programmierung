#include "benotung.h"
#include "fachnote.h"

fachnote::fachnote(const std::string& f, const benotung& b)
: fach(f), note(b)
{
    if(f.size() == 0){
        throw std::invalid_argument("unzulaessiger Fachname");
    }
}