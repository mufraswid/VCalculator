#include "button.h"

Button::Button()
{

}

void Button::onClick(int *a, int b){
    *a *= 10;
    *a += b;
}
