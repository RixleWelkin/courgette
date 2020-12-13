#include <string>
#include <vector>
#include <iostream>

class Menu 
{
  public:
    Menu();
    ~Menu();
    void print_menu(int current_menu);
    int get_choice(int current_menu);

    int previous_menu [10];
    int current_menu;
    int user_input;

  private:
  
  protected:
  
};
