#ifndef TIC_TAC_TOE_BOT_H
#define TIC_TAC_TOE_BOT_H

#include <iostream>
struct Bot
{
public:
    static void move(unsigned int (&grid)[3][3]);
private:
    static int minimax(unsigned int grid[3][3], int depth, bool maximizing_player);
    static int evaluate(unsigned int grid[3][3]);
    static bool cells_left(unsigned int grid[3][3]);
};
#endif //TIC_TAC_TOE_BOT_H
