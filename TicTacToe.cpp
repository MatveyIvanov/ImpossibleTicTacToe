// TicTacToe

#include <iostream>
#include "Field.h"
#include "Computer.h"
#include <Windows.h>


int main()
{
    ContextSettings settings;
    settings.antialiasingLevel = 8;
    RenderWindow window(VideoMode(1920, 1080), L"TicTacToe", Style::Default, settings);
    Menu menu;
    Field field(window);
    Player player;
    Computer computer;

    Texture defaultButton, menuButton, restartButton, closeButton;
    if (!defaultButton.loadFromFile("default_button.png"))
        std::cout << "Error loading default button" << std::endl;
    if (!menuButton.loadFromFile("menu_button.png"))
        std::cout << "Error loading menu button" << std::endl;
    if (!restartButton.loadFromFile("restart_button.png"))
        std::cout << "Error loading restart button" << std::endl;
    if (!closeButton.loadFromFile("close_button.png"))
        std::cout << "Error loading close button" << std::endl;

    Font font;
    if (!font.loadFromFile("PottaOne-Regular.ttf"))
        std::cout << "Error loading font" << std::endl;

    Texture bg1, bg2;
    if (!bg1.loadFromFile("bg1.png"))
        std::cout << "Error loading background" << std::endl;
    if (!bg2.loadFromFile("bg2.png"))
        std::cout << "Error loading background" << std::endl;
    Sprite background1, background2;
    background1.setTexture(bg1);
    background2.setTexture(bg2);
    background1.setPosition(0, 0);
    background2.setPosition(window.getSize().x - 1, 0);
    
    srand(time(NULL));
    int firstToMove = rand() % 2 + 1;
    field.set_current_move(((firstToMove == 2) ? "player" : "computer"));
    if (field.get_current_move() == "player") {
        player.set_suit("cross");
        computer.set_suit("zero");
    }
    else {
        player.set_suit("zero");
        computer.set_suit("cross");
    }

    while (window.isOpen()) {
        window.clear();
        
        background1.setPosition(background1.getPosition().x - 0.1, background1.getPosition().y);
        background2.setPosition(background2.getPosition().x - 0.1, background2.getPosition().y);
        if (background1.getPosition().x + window.getSize().x < 0)
            background1.setPosition(window.getSize().x + background2.getPosition().x - 1, 0);
        if (background2.getPosition().x + window.getSize().x < 0)
            background2.setPosition(window.getSize().x + background1.getPosition().x - 1, 0);
        window.draw(background1);
        window.draw(background2);

        Event event;
        switch (menu.game_is_started()) {
        case true:
            field.draw_field(window);
            field.draw_menu_button(window, menuButton);
            field.draw_restart_button(window, restartButton);
            break;
        case false:
            menu.draw_menu(window, defaultButton, closeButton, font);
            break;
        }
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            if (field.get_current_move() == "player" || !menu.game_is_started() || field.get_game_over()) {
                if (event.type == Event::MouseButtonPressed) {
                    Vector2i mousePos = Mouse::getPosition(window);
                    Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                    if (!menu.game_is_started()) {
                        if (menu.get_difficulty_button().getGlobalBounds().contains(mousePosF)) {
                            menu.change_difficulty();
                        }
                        if (menu.get_start_button().getGlobalBounds().contains(mousePosF)) {
                            menu.start_game(true);
                        }
                        if (menu.get_close_button().getGlobalBounds().contains(mousePosF)) {
                            window.close();
                        }
                    }
                    else {
                        if (field.get_menu_button().getGlobalBounds().contains(mousePosF)) {
                            menu.start_game(false);
                            firstToMove = rand() % 2 + 1;
                            field.set_current_move(((firstToMove == 2) ? "player" : "computer"));
                            field.reset(computer, player);
                        }
                        if (field.get_restart_button().getGlobalBounds().contains(mousePosF)) {
                            firstToMove = rand() % 2 + 1;
                            field.set_current_move(((firstToMove == 2) ? "player" : "computer"));
                            field.reset(computer, player);
                        }
                        if ((!field.get_game_over()) && (mousePos.x >= field.get_field_start().x) && (mousePos.x <= field.get_field_start().x + field.get_cell_size() * 3) && (mousePos.y >= field.get_field_start().y) && (mousePos.y <= field.get_field_start().y + field.get_cell_size() * 3)) {
                            int* position = field.spot_cell(mousePos);
                            if (field.cell_is_available(position)) {
                                player.move(field, position);
                                field.set_current_move("computer");
                            }
                        }
                    }
                }
            }
            else if (!field.get_game_over()) {
                Sleep(500);
                field.computer_move(window, computer, field, menu);
                field.set_current_move("player");
            }
        }
        if (menu.game_is_started())
            field.draw_moves(window);
        if (field.get_game_over())
            field.draw_winner(window, font);
        window.display();
    }
}


