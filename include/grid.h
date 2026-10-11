#ifndef GRID_H
#define GRID_H

/**
 * @brief converts a row and column into a flat array index
 * @param row row index
 * @param col column index
 * @param cols number of columns
 * @return index in the flat array
 */
int grid_index(int row, int col, int cols);

/**
 * @brief checks whether a position is inside a grid
 * @param row row index
 * @param col column index
 * @param rows number of rows
 * @param cols number of columns
 * @return true if the position is valid, otherwise false
 */
bool in_bounds(int row, int col, int rows, int cols);

#endif
