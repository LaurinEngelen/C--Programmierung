#include "fachnoten_liste.h"
#include "fachnote.h"

//----------------------------------------------------- Klasse intlist::element
class fachnoten_liste::element final {
public:
    element *next;
    fachnote* n;

    element(element *e, fachnote* m) : next(e), n(m) {}

    friend class fachnoten_liste;
    friend class fachnoten_liste::iterator;
};

//----------------------------------------- Member-Funktionen intlist::iterator
fachnoten_liste::iterator::iterator(element *e) : current(e) {}

bool fachnoten_liste::iterator::operator!=(const iterator& i) const {
    return this->current != i.current;
}

fachnote*& fachnoten_liste::iterator::operator*() const {
    return this->current->n;
}

fachnoten_liste::iterator& fachnoten_liste::iterator::operator++() {
    this->current = this->current->next;
    return *this;
}

//--------------------------------------------------- Member-funktionen intlist

fachnoten_liste::~fachnoten_liste() {
    element *e = this->head;
    while (e != nullptr) {
        element *x = e;
        e = e->next;
        delete_fachnote(x->n);
        delete x;

    }
}

fachnoten_liste::fachnoten_liste(void (*delete_fachnote)(fachnote*))
    : head(nullptr), delete_fachnote(delete_fachnote) {

}

fachnoten_liste &fachnoten_liste::insert(fachnote *n) {
    this->head = new element(this->head, n);
    return *this;
}

fachnoten_liste::iterator fachnoten_liste::begin() {
    return fachnoten_liste::iterator(this->head);
}

fachnoten_liste::iterator fachnoten_liste::end() {
    return fachnoten_liste::iterator(nullptr);
}
