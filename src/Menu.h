#ifndef MENU_H
#define MENU_H

class Menu 
{
  public:
    Menu();
    ~Menu();
    void print_menu(int menu_select);
    int get_user_choice();
    int figure_type_menu();
    int figure_orientation_menu();
    int figure_position_menu(int *Fig_HPos, int *Fig_VPos);
    int figure_size_menu(int *Fig_W, int *Fig_H);
    int image_size_menu(int *Im_W, int *Im_H);
    int main_menu();

    int menu_select;

  private:
  
  protected:
  
};
#endif // MENU_H