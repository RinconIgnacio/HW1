#include "analysis.h"
#include "grid.h"
int count_above(const double* temps, int rows, int cols, double threshold){
  int count = 0;

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            int index = grid_index(row, col, cols);

            if (temps[index] > threshold) {
                count++;
            }
        }
    }

    return count;
}
bool station_average(const double* temps, int rows, int cols, int station, double& average) {
    if (cols <= 0 || !in_bounds(station, 0, rows, cols)) {
        return false;
    }

    double total = 0.0;

    for (int day = 0; day < cols; day++) {
        int index = grid_index(station, day, cols);
        total += temps[index];
    }

    average = total / cols;
    return true;
}

bool day_average(const double* temps, int rows, int cols, int day, double& average) {
    if (rows <= 0 || !in_bounds(0, day, rows, cols)) {
        return false;
    }

    double total = 0.0;

    for (int station = 0; station < rows; station++) {
        int index = grid_index(station, day, cols);
        total += temps[index];
    }

    average = total / rows;
    return true;
}

bool find_hottest(const double* temps, int rows, int cols, int& hot_row, int& hot_col) {
    if (rows <= 0 || cols <= 0) {
        return false;
    }

    int best_row = 0;
    int best_col = 0;
    double highest = temps[grid_index(0, 0, cols)];

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            int index = grid_index(row, col, cols);

            if (temps[index] > highest) {
                highest = temps[index];
                best_row = row;
                best_col = col;
            }
        }
    }

    hot_row = best_row;
    hot_col = best_col;

    return true;
}
