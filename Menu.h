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
    int fig_value;
    bool is_end;

    void setID(int ID);
    void setlimit(int limit);
    void setend(bool ends);
    void setvalue();
    void setlines(std::string **lines);

    void print_menu();
    void assign_value(int user_input, Menu *menu_list);
    int get_user_choice();
    int menu_switch(int user_input);
    bool start_menu(Menu *menu_list);

  private:


  protected:
  
};

#endif // MENU_H