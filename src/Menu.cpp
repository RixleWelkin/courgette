#include <iostream>
#include <string>
#include <vector>
#include "Menu.h"


Menu::Menu(){}
Menu::~Menu(){}

int Menu::get_user_choice()
{
    int user_input = 0;
    char confirm = '0';
    while(confirm != 'y' && confirm != 'Y')
    {
        std::cin>>user_input;
        std::cout<<"You entered : "<<user_input<<std::endl<<"Press 'y' to confirm"<<std::endl;
        std::cin>>confirm;
    }
    return user_input;
}

int Menu::figure_type_menu()
{
    int type = 0;

    std::cout<<std::endl<<std::endl<<"-----Figure type menu-----"<<std::endl<<std::endl;
    while (type !=1 && type !=2 && type !=3)
    {
        std::cout<<"Select the desired figure : "<<std::endl;
        std::cout<<"1 : Rectangle"<<std::endl;
        std::cout<<"2 : Triangle"<<std::endl;
        std::cout<<"3 : Cross"<<std::endl;
        type = get_user_choice();
        if(type !=1 && type !=2 && type !=3)
            std::cout<<std::endl<<std::endl<<"Input error, try again"<<std::endl<<std::endl;
    }

    return type;
}

int Menu::figure_orientation_menu()
{
    int orientation = 0;

    std::cout<<std::endl<<std::endl<<"-----Figure orientation menu-----"<<std::endl<<std::endl;
    while (orientation !=1 && orientation !=2)
    {
        std::cout<<"Select the desired orientation : "<<std::endl;
        std::cout<<"1 : Straight"<<std::endl;
        std::cout<<"2 : Diagonal"<<std::endl;
        orientation = get_user_choice();
        if(orientation !=1 && orientation !=2)
            std::cout<<std::endl<<std::endl<<"Input error, try again"<<std::endl<<std::endl;
    }

    return orientation;
}

void Menu::figure_position_menu(int *Fig_HPos, int *Fig_VPos)
{
    std::cout<<std::endl<<std::endl<<"-----Figure position menu-----"<<std::endl<<std::endl;
    std::cout<<"Enter the desired horizontal position : "<<std::endl;
    *Fig_HPos = get_user_choice();
    std::cout<<"Enter the desired vertical position : "<<std::endl;
    *Fig_VPos = get_user_choice();
}

void Menu::figure_size_menu(int *Fig_W, int *Fig_H)
{
    std::cout<<std::endl<<std::endl<<"-----Figure size menu-----"<<std::endl<<std::endl;
    std::cout<<"Enter the desired width : "<<std::endl;
    *Fig_W = get_user_choice();
    std::cout<<"Enter the desired height : "<<std::endl;
    *Fig_H = get_user_choice();
}

void Menu::image_size_menu(int *Im_W, int *Im_H)
{
    std::cout<<std::endl<<std::endl<<"-----Image size menu-----"<<std::endl<<std::endl;
    std::cout<<"Enter the desired width : "<<std::endl;
    *Im_W = get_user_choice();
    std::cout<<"Enter the desired height : "<<std::endl;
    *Im_H = get_user_choice();
}

int Menu::main_menu()
{
    int menu_select = 0;

    std::cout<<std::endl<<std::endl<<"-----Figure type menu-----"<<std::endl<<std::endl;
    while (menu_select !=1 && menu_select !=2 && menu_select !=3)
    {
        std::cout<<"Select the desired figure : "<<std::endl;
        std::cout<<"1 : Figure type menu"<<std::endl;
        std::cout<<"2 : Figure orientation menu"<<std::endl;
        std::cout<<"3 : Figure position menu"<<std::endl;
        std::cout<<"4 : Figure size menu"<<std::endl;
        std::cout<<"5 : Image size menu"<<std::endl;
        std::cout<<"8 : Save (not available yet)"<<std::endl;
        std::cout<<"9 : Draw (not available yet)"<<std::endl;
        menu_select = get_user_choice();
        if(menu_select !=1 && menu_select !=2 && menu_select !=3)
            std::cout<<std::endl<<std::endl<<"Input error, try again"<<std::endl<<std::endl;
    }

    return menu_select;
}

int main(int argc, char **argv)
{
    Menu menu;

    int menu_select = 0;

    int Fig_Type = 0;
    int Fig_Orientation = 0;

    int Fig_HPos = 0;
    int Fig_VPos = 0;
    int Fig_W = 0;
    int Fig_H = 0;
    int Im_W = 0;
    int Im_H = 0;

    int *Pt_Fig_HPos = &Fig_HPos;
    int *Pt_Fig_VPos = &Fig_VPos;
    int *Pt_Fig_W = &Fig_W;
    int *Pt_Fig_H = &Fig_H;
    int *Pt_Im_W = &Im_W;
    int *Pt_Im_H = &Im_H;

    while(menu_select >= 0)
    {
        main_menu();
        switch (menu_select)
        {
        case 1:
            Fig_Type = menu.figure_type_menu();
            break;
        case 2:
            Fig_Orientation = menu.figure_orientation_menu();
            break;
        case 3:
            menu.figure_position_menu(Pt_Fig_VPos, Pt_Fig_HPos);
            break;
        case 4:
            menu.figure_size_menu(Pt_Fig_W, Pt_Fig_H);
            break;
        case 5:
            menu.image_size_menu(Pt_Im_W, Pt_Im_H);
            break;
        default:
            break;
        }
    }

    return 0;
}
