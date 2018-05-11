#include "game.h"
#include <ncurses.h>

void MainMenu()
{
    char choices[4][30] = {"Easy Mode", "Normal Mode", "Hard Mode", "Exit"};
    int c;
    ITEM *mode_arr[5];
    MENU *menu;
    for (int i = 0; i < 4; ++i)
        mode_arr[i] = new_item(choices[i], "");
    mode_arr[4] = nullptr;
    menu = new_menu(mode_arr);
    bool quit = false;
    while (!quit)
    {
        post_menu(menu);
        refresh();
        bool enter = false;
        while (!enter)
        {
            c = getch();
            switch (c)
            {
            case KEY_DOWN:
                menu_driver(menu, REQ_DOWN_ITEM);
                break;
            case KEY_UP:
                menu_driver(menu, REQ_UP_ITEM);
                break;
            case 10:
                enter = true;
                if (item_index(current_item(menu)) == 3)
                    quit = true;
                else
                {
                    Game game(item_index(current_item(menu)));
                    game.MainGame();
                }
                break;
            }
        }
        unpost_menu(menu);
        clear();
    }
    free_menu(menu);
    for (int i = 0; i < 4; ++i)
        free_item(mode_arr[i]);
}