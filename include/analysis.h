#ifndef ANALYSIS_H
#define ANALYSIS_H

/**
 * @brief gets the average temperature for a station
 * @param temps temperature readings
 * @param rows number of stations
 * @param cols number of days
 * @param station station index
 * @param average where the result is stored
 * @return true if valid otherwise false
 */
bool station_average(const double* temps, int rows, int cols, int station, double& average);

/**
 * @brief gets the average temperature for a day
 * @param temps temperature readings
 * @param rows number of stations
 * @param cols number of days
 * @param day day index
 * @param average where the result is stored
 * @return true if valid otherwise false
 */
bool day_average(const double* temps, int rows, int cols, int day, double& average);

/**
 * @brief finds the highest temperature
 * @param temps temperature readings
 * @param rows number of stations
 * @param cols number of days
 * @param hot_row row of the highest temperature
 * @param hot_col column of the highest temperature
 * @return true if a temperature was found otherwise false
 */
bool find_hottest(const double* temps, int rows, int cols, int& hot_row, int& hot_col);

/**
 * @brief counts temperatures above a given number
 * @param temps temperature readings
 * @param rows number of stations
 * @param cols number of days
 * @param threshold temperature to compare against
 * @return number of temperatures above the threshold
 */
int count_above(const double* temps, int rows, int cols, double threshold);

#endif
