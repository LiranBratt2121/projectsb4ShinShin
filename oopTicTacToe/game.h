#pragma once

#include <array>
#include <iostream>
#include <string>

class Game {
    #define LOG(x) std::cout << x

    public:
        Game();
        void game_loop();
        void print_board() const;
        bool play(int idx);

    private:
        std::array<std::array<char, 3>, 3> m_board;
        int m_game_turn;
        char m_current_player;

        struct GameSymbols{
            const char m_firstPlayer = 'X';
            const char m_secondsPlayer = 'Y';
            const char m_default = '0';
        } m_symbols;

        void reset_board();
        bool got_winner();

        bool got_draw();
        bool __check_rows();
        bool __check_columns();
        bool __check_diagonals();
};

