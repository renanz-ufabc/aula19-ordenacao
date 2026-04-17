#include "element.h"
#include <stdio.h>


int element_compare(Element a, Element b)
{
    return (a > b) - (a < b);
}
void element_swap(Element * x, Element * y)
{
    Element xCopy = *x;

    *x = *y;
    *y = xCopy;
}

void element_print(Element elem)
{
    printf("%d", elem);
}
void element_print_sp(Element elem)
{
    printf("%d ", elem);
}
void element_print_ln(Element elem)
{
    printf("%d\n", elem);
}
