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
