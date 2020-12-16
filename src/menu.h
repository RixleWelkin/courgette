#ifndef MENU_H
#define MENU_H

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

class Menu 
{
  public:
    Menu();
    ~Menu();
    
    int menu_ID;
    int accepted_input_limit;
    std::string menu_line[10];

    void setID(const int ID){menu_ID = ID;}
    void setlimit(const int limit){accepted_input_limit = limit;}
    void setlines(const std::string *lines){*menu_line = *lines;}

  private:
    void print_menu(const std::string *menu_line);
    int get_user_choice(Menu *menu_list, int *menu_ID);
    bool start_menu(Menu *menu_list, int *menu_ID);

    int user_input;

  protected:
  
};

#endif // MENU_H