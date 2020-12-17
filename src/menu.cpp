#include <iostream>
#include <string>
#include <vector>
#include <any>
#include <variant>
#include <type_traits>
#include <optional>
#include <sstream>
#include <limits>
#include <cctype>
#include "menu.h"


//All menu lines
std::string main_line[10] = 
{
    "Main menu",
    "Figure type menu",
    "Figure orientation menu",
    "Figure position menu",
    "Figure size menu",
    "Image size menu",
    "Save (not available yet)",
    "Draw (not available yet)",
    "0",
    "Select the desired menu"
};

std::string figure_type_line[10] = 
{
    "Figure type menu",
    "Rectangle",
    "Triangle",
    "Cross",
    "Segment",
    "Point",
    "0",
    "0",
    "0",
    "Select the desired figure"
};

std::string figure_orientation_line[10] = 
{
    "Figure orientation menu",
    "Straight",
    "Diagonal",
    "0",
    "0",
    "0",
    "0",
    "0",
    "0",
    "Select the desired orientation"
};

std::string figure_position_line[10] = 
{
    "Figure position menu",
    "Horizontal",
    "Vertical",
    "0",
    "0",
    "0",
    "0",
    "0",
    "0",
    "Select what you whant to set",
};

std::string figure_size_line[10] = 
{
    "Figure size menu",
    "Width",
    "Height",
    "0",
    "0",
    "0",
    "0",
    "0",
    "0",
    "Select what you whant to set"
};

std::string image_size_line[10] = 
{
    "Image size menu",
    "Width",
    "Height",
    "0",
    "0",
    "0",
    "0",
    "0",
    "0",
    "Select what you whant to set"
};

std::string figure_horizontal_line[10] = 
{
    "Figure horizontal position",
    "0",
    "0",
    "0",
    "0",
    "0",
    "0",
    "0",
    "0",
    "Type in the desired value"
};

std::string figure_vertical_line[10] = 
{
    "Figure vertical position",
    "0",
    "0",
    "0",
    "0",
    "0",
    "0",
    "0",
    "0",
    "Type in the desired value"
};

std::string figure_width_line[10] = 
{
    "Figure width",
    "0",
    "0",
    "0",
    "0",
    "0",
    "0",
    "0",
    "0",
    "Type in the desired value"
};

std::string figure_height_line[10] = 
{
    "Figure height",
    "0",
    "0",
    "0",
    "0",
    "0",
    "0",
    "0",
    "0",
    "Type in the desired value"
};

std::string image_width_line[10] = 
{
    "Image width",
    "0",
    "0",
    "0",
    "0",
    "0",
    "0",
    "0",
    "0",
    "Type in the desired value"
};

std::string image_height_line[10] = 
{
    "Image height",
    "0",
    "0",
    "0",
    "0",
    "0",
    "0",
    "0",
    "0",
    "Type in the desired value"
};
//All menu lines

//Figure variables
int Fig_Type = 0;

int Fig_Orientation = 0;

int Fig_HPosition = 0;
int Fig_VPossition = 0;

int Fig_Width = 0;
int Fig_Height = 0;

int Im_Width = 0;
int Im_Height = 0;
//Figure variables


//            _    _  _                     _    _           _
//  ___  _ _ | |_ | |<_> ___  ._ _ _  ___ _| |_ | |_  ___  _| | ___
// | . \| | || . \| || |/ | ' | ' ' |/ ._> | |  | . |/ . \/ . |<_-<
// |  _/`___||___/|_||_|\_|_. |_|_|_|\___. |_|  |_|_|\___/\___|/__/
// |_|

Menu::Menu(){}

Menu::~Menu(){}

void Menu::setID(int ID)
{
    menu_ID = ID;
}

void Menu::setlimit(int limit)
{
    accepted_input_limit = limit;
}

void Menu::setend(bool ends)
{
    is_end = ends;
}

void Menu::setlines(std::string **lines)
{
    std::string *line;
    line = *lines;

    for(int i = 0; i < 10; i++)
        menu_line[i] = line[i];
}


//            _             _                      _    _           _
//  ___  _ _ <_> _ _  ___ _| |_ ___  ._ _ _  ___ _| |_ | |_  ___  _| | ___
// | . \| '_>| || | |<_> | | | / ._> | ' ' |/ ._> | |  | . |/ . \/ . |<_-<
// |  _/|_|  |_||__/ <___| |_| \___. |_|_|_|\___. |_|  |_|_|\___/\___|/__/
// |_|

void Menu::print_menu()
{
    std::cout<<std::endl<<std::endl<<"----------"<<menu_line[0]<<"----------"<<std::endl<<std::endl;
    std::cout<<menu_line[9]<<" : "<<std::endl;
    for(int i = 1; menu_line[i] != "0"; i++)
        std::cout<<i<<" : "<<menu_line[i]<<std::endl;
    std::cout<<std::endl<<"0 : Return"<<std::endl<<std::endl;
}

void Menu::assign_value(int user_input, Menu *menu_list)
{
    switch (menu_ID)
    {
            break;
        case 1 :
            menu_list[0].Fig_value[0] = user_input;
            break;
        case 2 :
            menu_list[0].Fig_value[1] = user_input;
            break;
        case 6 :
            menu_list[0].Fig_value[2] = user_input;
            break;
        case 7 :
            menu_list[0].Fig_value[3] = user_input;
            break;
        case 8 :
            menu_list[0].Fig_value[4] = user_input;
            break;
        case 9 :
            menu_list[0].Fig_value[5] = user_input;
            break;
        case 10 :
            menu_list[0].Fig_value[6] = user_input;
            break;
        case 11 :
            menu_list[0].Fig_value[7] = user_input;
            break;
    }
}

int Menu::get_user_choice()
{
    int user_input = 0;

    if(!(std::cin >> user_input) || user_input < 0 || user_input > accepted_input_limit)
    {
        std::cout<<std::endl<<"Invalid input, please try again"<<std::endl<<std::endl;
        print_menu();
        user_input = get_user_choice();
    }

    return user_input;
}

int Menu::menu_switch(int user_input)
{
    switch (menu_ID)
    {
        case 3 :
            if(user_input == 1)
                return 6;
            else
                return 7;
            break;
        case 4 :
            if(user_input == 1)
                return 8;
            else
                return 9;
            break;
        case 5 :
            if(user_input == 1)
                return 10;
            else
                return 11;
            break;
    }
    return 0;
}

bool Menu::start_menu(Menu *menu_list)
{
    int next_menu;
    bool retour;
    print_menu();
    int user_input = get_user_choice();

    if(is_end == true)
    {
        assign_value(user_input, menu_list);
        return false;
    }

    if(user_input == 0)
        return false;
    else
    {
        std::cout<<std::endl<<"user input pre switch = "<<user_input<<std::endl<<std::endl;
        std::cout<<std::endl<<"menu ID pre switch = "<<menu_ID<<std::endl<<std::endl;
        next_menu = menu_switch(user_input);
        std::cout<<std::endl<<"user input post switch = "<<user_input<<std::endl<<std::endl;
        std::cout<<std::endl<<"menu_ID post switch = "<<menu_ID<<std::endl<<std::endl;
        retour = menu_list[user_input].start_menu(menu_list);
    }

    if(retour == false)
        return start_menu(menu_list);
    else
        return true;
}

int main(int argc, char **argv)
{
    int IDs[12] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    bool ends[12] = {false, true, true, false, false, false, true, true, true, true, true, true};
    int limits[12] = {5, 5, 2, 2, 2, 2, 10000, 10000, 10000, 10000, 10000, 10000};
    std::string *lines[12] = 
    {
        main_line,
        figure_type_line,
        figure_orientation_line,
        figure_position_line,
        figure_size_line,
        image_size_line,
        figure_horizontal_line,
        figure_vertical_line,
        figure_width_line,
        figure_height_line,
        image_width_line,
        image_height_line
    };

    Menu menu_list[12];

    for(int i = 0; i < 12; i++)
    {
        menu_list[i].setID(IDs[i]);
        menu_list[i].setlimit(limits[i]);
        menu_list[i].setend(ends[i]);
        menu_list[i].setlines(&lines[i]);
    }

    menu_list[0].start_menu(menu_list);


    std::cout<<std::endl<<std::endl
    <<std::endl<<"Fig_Type = "<<Fig_Type
    <<std::endl<<"Fig_Orientation = "<<Fig_Orientation
    <<std::endl<<"Fig_HPosition = "<<Fig_HPosition
    <<std::endl<<"Fig_VPossition = "<<Fig_VPossition
    <<std::endl<<"Fig_Width = "<<Fig_Width
    <<std::endl<<"Fig_Height = "<<Fig_Height
    <<std::endl<<"Im_Width = "<<Im_Width
    <<std::endl<<"Im_Height = "<<Im_Height
    <<std::endl<<std::endl;

    return 0;
}