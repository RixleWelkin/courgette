#include "Menu.h"

Menu::Menu(){}
Menu::~Menu(){}

void print_menu(int current_menu)
{
    std::cout<<"ecrit"<<std::endl;
}

void get_choice(int *user_input)
{
    std::cin>>*user_input;
    std::cout<<"you pressed : "<<*user_input<<std::endl;
}

void print_choice(int *user_input)
{
    std::cout<<*user_input<<std::endl;
}

int current_menu = 0;
int user_input = 0;

int main(int argc, char **argv)
{
    Menu::print_menu;
    Menu::get_choice;
    return 0;
}
