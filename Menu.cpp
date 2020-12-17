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
#include "Drawing.h"
#include "Figure.h"
#include "Croix.h"
#include "Rectangle.h"
#include "Carre.h"
#include "Triangle.h"
#include "Menu.h"


//All menu lines
std::string main_line[10] = 
{
    "Main menu",
    "Figure type menu",
    "Figure orientation menu (Doesn't work, bonus feature)",
    "Figure position menu",
    "Figure size menu",
    "Image size menu",
    "0",
    "0",
    "0",
    "Select the desired menu"
};

std::string figure_type_line[10] = 
{
    "Figure type menu",
    "Rectangle",
    "Triangle (Looks a bit weird but we don't judge)",
    "Cross",
    "Square",
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
    "Figure width (Default 100)",
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
    "Figure height (Default 100)",
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
    "Image width (Default 500)",
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
    "Image height (Default 500)",
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

void Menu::setvalue()
{
    fig_value = 0;
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
    if(is_end == false)
    {
        if(menu_ID != 0)
            std::cout<<std::endl<<"0 : Return"<<std::endl<<std::endl;
        else
            std::cout<<std::endl<<"0 : Draw the figure"<<std::endl<<std::endl;
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
        default :
            return user_input;
            break;
    }
}

bool Menu::start_menu(Menu *menu_list)
{
    int next_menu;
    bool retour;
    print_menu();
    int user_input = get_user_choice();

    if(is_end == true)
    {
        fig_value = user_input;
        return false;
    }

    if(user_input == 0)
        return false;
    else
    {
        next_menu = menu_switch(user_input);
        retour = menu_list[next_menu].start_menu(menu_list);
    }

    if(retour == false)
        return start_menu(menu_list);
    else
        return true;
}
// __  __        _       
//|  \/  | __ _ (_) _ _  
//| |\/| |/ _` || || ' \ 
//|_|  |_|\__/_||_||_||_|
//
int main(int argc, char **argv)
{
    int IDs[12] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    bool ends[12] = {false, true, true, false, false, false, true, true, true, true, true, true};
    int limits[12] = {6, 5, 2, 2, 2, 2, 10000, 10000, 10000, 10000, 10000, 10000};
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
        menu_list[i].setvalue();
        menu_list[i].setlines(&lines[i]);
    }
    //Default values
    menu_list[1].fig_value=0;
    menu_list[6].fig_value=250;
    menu_list[7].fig_value=250;
    menu_list[8].fig_value=100;
    menu_list[9].fig_value=100;
    menu_list[10].fig_value=500;
    menu_list[11].fig_value=500;
    
   
    int add_figure = 1;
    Drawing draw(menu_list[10].fig_value, menu_list[11].fig_value);
    while(add_figure == 1)
    {
        menu_list[0].start_menu(menu_list);
        std::cout<<"Add another figure to image ? (1 = Yes | 0 = No)"<<std::endl;
        std::cin>>add_figure;
    switch(menu_list[1].fig_value)
    {
        case 1:
        {
            Rectangle rectangle(menu_list[8].fig_value, menu_list[9].fig_value);
            draw.DrawCanva(rectangle.figure,rectangle.hauteur,rectangle.largeur,menu_list[6].fig_value,menu_list[7].fig_value);
            break;
        }
        case 2:
        {
            Triangle triangle(menu_list[8].fig_value,menu_list[9].fig_value);
            draw.DrawCanva(triangle.figure,triangle.hauteur,triangle.largeur,menu_list[6].fig_value,menu_list[7].fig_value);
            break;
        }
        case 3:
        {
            Croix croix(menu_list[8].fig_value, menu_list[9].fig_value);
            draw.DrawCanva(croix.figure,croix.hauteur,croix.largeur,menu_list[6].fig_value,menu_list[7].fig_value);
            break;
        }
           case 4:
        {
            Carre carre(menu_list[8].fig_value);
            draw.DrawCanva(carre.figure,carre.hauteur,carre.largeur,menu_list[6].fig_value,menu_list[7].fig_value);
            break;
        }
           case 5:
        {
            Point point(menu_list[8].fig_value / 2, menu_list[9].fig_value / 2);
            Figure figPoint(menu_list[8].fig_value, menu_list[9].fig_value);
            figPoint.drawPoint(point, 5);
            draw.DrawCanva(figPoint.figure,figPoint.hauteur,figPoint.largeur,menu_list[6].fig_value,menu_list[7].fig_value);
            break;
        }
    };
    }
    //Debug values
    /*std::cout<<std::endl;
    for(int i = 0; i < 12; i++)
        std::cout<<menu_list[i].fig_value<<std::endl;
    std::cout<<std::endl;*/ 
    
    draw.save(std::string("test_image.bmp"));
    return 0;
}
