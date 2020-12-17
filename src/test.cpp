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
    "Select the desired menu : "
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
    "Select the desired figure : "
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
    "Select the desired orientation : "
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
    "Select what you whant to set : ",
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
    "Select what you whant to set : "
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
    "Select what you whant to set : "
};
//All menu lines

void setlines(std::string **lines,std::string *menu_line)
{
    std::string *line;
    line = *lines;

    for(int i = 0; i < 10; i++)
        menu_line[i] = line[i];
}

int main(int argc, char **argv)
{
    std::string *lines[6] = 
    {
        main_line,
        figure_type_line,
        figure_orientation_line,
        figure_position_line,
        figure_size_line,
        image_size_line
    };

    std::string *menu_list[6];

    for(int i = 0; i <= 5; i++)
    {
        setlines(&lines[i], menu_list[i]);
    }


    int a = 3;
    int *b = &a;
    int **c = &b;

    std::cout<<a<<std::endl;    //x = valeur
    std::cout<<b<<std::endl;    //pt = adresse
    std::cout<<*b<<std::endl;   //*pt = valeur
    std::cout<<c<<std::endl;    //dpt = adresse pointeur
    std::cout<<*c<<std::endl;   //*dpt = adresse
    std::cout<<**c<<std::endl;  //**dpt = valeur


    return 0;
}