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
const std::string main_line[10] = 
{
    "Main menu",
    "Figure type menu",
    "Figure orientation menu",
    "Figure position menu",
    "Figure size menu",
    "Image size menu",
    "Save (not available yet)",
    "Draw (not available yet)",
    NULL,
    "Select the desired menu : "
};

const std::string figure_type_line[10] = 
{
    "Figure type menu",
    "Rectangle",
    "Triangle",
    "Cross",
    "Segment",
    "Point",
    NULL,
    NULL,
    NULL,
    "Select the desired figure : "
};

const std::string figure_orientation_line[10] = 
{
    "Figure orientation menu",
    "Straight",
    "Diagonal",
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    "Select the desired orientation : "
};

const std::string figure_position_line[10] = 
{
    "Figure position menu",
    "Horizontal",
    "Vertical",
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    "Select what you whant to set : ",
};

const std::string figure_size_line[10] = 
{
    "Figure size menu",
    "Width",
    "Height",
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    "Select what you whant to set : "
};

const std::string image_size_line[10] = 
{
    "Image size menu",
    "Width",
    "Height",
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    "Select what you whant to set : "
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

//            _             _                      _    _           _
//  ___  _ _ <_> _ _  ___ _| |_ ___  ._ _ _  ___ _| |_ | |_  ___  _| | ___
// | . \| '_>| || | |<_> | | | / ._> | ' ' |/ ._> | |  | . |/ . \/ . |<_-<
// |  _/|_|  |_||__/ <___| |_| \___. |_|_|_|\___. |_|  |_|_|\___/\___|/__/
// |_|

void Menu::print_menu(const std::string *menu_line)
{
    std::cout<<std::endl<<std::endl<<"----------"<<menu_line[0]<<"----------"<<std::endl<<std::endl;
    std::cout<<menu_line[9]<<" : "<<std::endl;
    for(int i = 1; menu_line[i] != NULL; i++)
        std::cout<<i<<" : "<<menu_line[i]<<std::endl;
    std::cout<<std::endl<<"0) Return"<<std::endl<<std::endl;
}

int get_user_choice(Menu *menu_list, int *menu_ID)
{
    int user_input = 0;

    if(!(std::cin >> user_input) || user_input < 0 || user_input > menu_list[*menu_ID]::accepted_input_limit)
    {
        std::cout<<std::endl<<"Invalid input, please try again"<<std::endl<<std::endl;
        print_menu(menu_line);
        user_input = get_user_choice(accepted_input_limit, menu_line);
    }

    return user_input;
}

bool Menu::start_menu(Menu *menu_list, int *ID)
{
    int next_menu;
    bool retour;
    print_menu(menu_line);
    user_input = get_user_choice(menu_list, menu_ID);

    if(user_input == 0)
        return false;
    else
    {
        next_menu = user_input;
        retour = start_menu(menu_list, menu_ID);
    }

    if(retour == false)
        retour = start_menu(menu_list, menu_ID);
    else
        return true;
}

int main(int argc, char **argv)
{
    /*
    Menu main_menu(0, 5, main_line);
    Menu figure_type_menu(1, 5, figure_type_line);
    Menu figure_orientation_menu(2, 2, figure_orientation_line);
    Menu figure_position_menu(3, 2, figure_position_line);
    Menu figure_size_menu(4, 2, figure_size_line);
    Menu image_size_menu(5, 2, image_size_line);
    */

    const int IDs[6] = {0, 1, 2, 3, 4, 5};
    const int limits[6] = {5, 5, 2, 2, 2, 2};
    const std::string *lines[6] = 
    {
        main_line,
        figure_type_line,
        figure_orientation_line,
        figure_position_line,
        figure_size_line,
        image_size_line
    };

    Menu menu_list[6];

    for(int i = 0; i <= 5; i++)
    {
        menu_list[i].setID(IDs[i]);
        menu_list[i].setlimit(limits[i]);
        menu_list[i].setlines(lines[i]);
    }
}
