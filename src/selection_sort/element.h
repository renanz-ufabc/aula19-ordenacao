#ifndef ELEMENT_H
#define ELEMENT_H
#include <limits.h>

#define ELEMENT_NULL INT_MIN


typedef int Element;


int element_compare(Element a, Element b);
void element_swap(Element * x, Element * y);

void element_print(Element elem);
void element_print_sp(Element elem);
void element_print_ln(Element elem);


#endif
