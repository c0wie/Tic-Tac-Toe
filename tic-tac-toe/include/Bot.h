#ifndef TIC_TAC_TOE_BOT_H
#define TIC_TAC_TOE_BOT_H

#include <vector>
#include <random>
#include "cell.h"
struct Bot
{
public:
    //checks all possible combination of O and X on grid and putting O in "the best" spot
    static void move(std::vector<std::vector<Cell>> &grid, const unsigned int &moves);
private:
    static void first_move(std::vector<std::vector<Cell>> &grid);
    static bool diagonal_move(std::vector<std::vector<Cell>> &grid, unsigned int ID );
    static bool vertical_move(std::vector<std::vector<Cell>> &grid, unsigned int ID );
    static bool horizontal_move(std::vector<std::vector<Cell>> &grid, unsigned int ID );
    static bool random_move(std::vector<std::vector<Cell>> &grid);

};
#endif //TIC_TAC_TOE_BOT_H
