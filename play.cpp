#include "play.hpp"
#include <iostream>
#include <vector>

std::vector<std::string> board = {" ", " ", " ", " ", " ", " ", " ", " ", " "};

int player = 1;
int position = 0;

void intro()
{

    std::cout << "\n======================\n";
    std::cout << "Welcome to Tic-Tac-Toe\n";
    std::cout << "======================\n\n";

    std::cout << "Player 1) X\n";
    std::cout << "Player 2) O\n";

    std::cout << "Each round you'll each pick a square (1-9) to draw your respective symbol.";

    std::cout << "     _________________ \n";
    std::cout << "    |     |     |     |\n";
    std::cout << "    |  1  |  2  |  3  |\n";
    std::cout << "    |_____|_____|_____|\n";
    std::cout << "    |     |     |     |\n";
    std::cout << "    |  4  |  5  |  6  |\n";
    std::cout << "    |_____|_____|_____|\n";
    std::cout << "    |     |     |     |\n";
    std::cout << "    |  7  |  8  |  9  |\n";
    std::cout << "    |_____|_____|_____|\n\n";
}

bool winner()
{

    bool winner = false;

    // checking if there's a winner on the rows
    if ((board[0] == board[1]) && (board[1] == board[2]) && board[0] != " ")
    {
        winner = true;
    }
    else if ((board[3] == board[4]) && (board[4] == board[5]) && board[3] != " ")
    {
        winner = true;
    }
    else if ((board[6] == board[7]) && board[7] == board[8] && board[6] != " ")
    {
        winner = true;
    }

    // checking if there's a winner in the columns
    else if ((board[0] == board[3]) && (board[3] == board[6]) && board[0] != " ")
    {
        winner = true;
    }
    else if ((board[1] == board[4]) && (board[4] == board[7]) && board[1] != " ")
    {
        winner = true;
    }
    else if ((board[2] == board[5]) && (board[5] == board[8]) && board[2] != " ")
    {
        winner = true;
    }

    // checking if there's a winner in the diagonals
    else if ((board[0] == board[4]) && (board[4] == board[8]) && board[0] != " ")
    {
        winner = true;
    }
    else if ((board[2] == board[4]) && (board[4] == board[6]) && board[2] != " ")
    {
        winner = true;
    }
    return winner;
}

bool board_filled()
{

    bool filled = true;
    for (int i = 0; i < 9; i++)
    {
        if (board[i] == " ")
        {
            filled = false;
        }
    }
    return filled;
}

void draw_board()
{

    std::cout << "     _________________ \n";
    std::cout << "    |     |     |     |\n";
    std::cout << "    |  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "  |\n";
    std::cout << "    |_____|_____|_____|\n";
    std::cout << "    |     |     |     |\n";
    std::cout << "    |  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "  |\n";
    std::cout << "    |_____|_____|_____|\n";
    std::cout << "    |     |     |     |\n";
    std::cout << "    |  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "  |\n";
    std::cout << "    |_____|_____|_____|\n\n";
}

void set_board_square()
{

    std::cout << "It is player " << player << " \n";
    std::cin >> position;

    if (board[position - 1] != " ")
    {
        std::cout << "That square is already filled.\n";
    }
}

void draw_update()
{

    if (player == 1)
    {

        board[position - 1] = "X";
    }
    else
    {

        board[position - 1] = "O";
    }
}

void change_player()
{

    if (player == 1)
    {

        player++;
    }
    else
    {

        player--;
    }
}

void turn()
{

    while (!winner() && !board_filled())
    {

        set_board_square();
        draw_update();
        change_player();
        draw_board();
    }
}

void game_over()
{

    if (winner())
    {
        std::cout << "We have a winner!\n";
    }
    else if (board_filled())
    {
        std::cout << "It's a tie!";
    }
}
