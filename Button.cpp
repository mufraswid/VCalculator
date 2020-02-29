#include "Button.h"

Button::Button(){}

Button::~Button(){}

void Button::onClick(int *a, int b){
    *a = (*a)*10 + b;
}
