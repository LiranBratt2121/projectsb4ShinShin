#include "game.h"

Game::Game() : m_game_turn(0), m_current_player(m_symbols.m_firstPlayer) {
    reset_board();
}

void Game::reset_board() {
    for (auto &row : m_board) {
        for (char &col : row) {
            col = m_symbols.m_default;
        }
    }
}

void Game::print_board() const {
    for (const auto &row : m_board) {
        for (const char &col : row) {
            std::cout << "| " << col << " ";
        }
        std::cout << "\n";
    }
}

bool Game::play(int idx) {
    int row = idx / 3;
    int col = idx % 3;

    if (m_board[row][col] != m_symbols.m_default) {
        return false;
    }

    m_current_player = (m_game_turn % 2 == 0) ? m_symbols.m_firstPlayer : m_symbols.m_secondsPlayer;

    m_board[row][col] = m_current_player;
    m_game_turn++;

    return true;
}

void Game::game_loop() {
    int idx;

    while (true) {
        print_board();
        LOG(m_current_player + std::string(" Please choose a location on the field [0-8]: "));
        std::cin >> idx;

        while (!play(idx)) {
            LOG(m_current_player + std::string(" Invalid location. Please try again: "));
            std::cin >> idx;
        }

        if (got_draw()) {
            LOG("The game is a draw");
            return;
        }

        if (got_winner()) {
            LOG(m_current_player + std::string(" has won the game"));
            return;
        }
    }
}

bool Game::__check_rows() {
    for (int i = 0; i < 3; ++i) {
        if (m_board[i][0] != m_symbols.m_default && m_board[i][0] == m_board[i][1] && m_board[i][1] == m_board[i][2]) {
            return true;
        }
    }
    return false;
}

bool Game::__check_columns() {
    for (int i = 0; i < 3; ++i) {
        if (m_board[0][i] != m_symbols.m_default && m_board[0][i] == m_board[1][i] && m_board[1][i] == m_board[2][i]) {
            return true;
        }
    }
    return false;
}

bool Game::__check_diagonals() {
    bool diag1 = (m_board[0][0] != m_symbols.m_default && m_board[0][0] == m_board[1][1] && m_board[1][1] == m_board[2][2]);
    bool diag2 = (m_board[0][2] != m_symbols.m_default && m_board[0][2] == m_board[1][1] && m_board[1][1] == m_board[2][0]);

    return diag1 || diag2;
}

bool Game::got_draw() {
    return m_game_turn == 9;
}

bool Game::got_winner() {
    return __check_diagonals() || __check_columns() || __check_rows();
}
