#ifndef REPORT_H
#define REPORT_H

#include "station.h"

/**
 * @brief prints the weather station report
 * @param stations list of stations
 * @param temps temperature readings
 * @param rows number of stations
 * @param cols number of days
 */
void print_report(const Station* stations, const double* temps, int rows, int cols);

#endif
