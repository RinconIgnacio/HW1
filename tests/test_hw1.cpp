#include <gtest/gtest.h>

#include "grid.h"
#include "analysis.h"
#include "station.h"

TEST(GridIndex, ConvertsCoordinates) {
    EXPECT_EQ(grid_index(0, 0, 4), 0);
    EXPECT_EQ(grid_index(1, 2, 4), 6);
    EXPECT_EQ(grid_index(2, 3, 4), 11);
}

TEST(InBounds, ChecksValidPositions) {
    EXPECT_TRUE(in_bounds(0, 0, 3, 4));
    EXPECT_TRUE(in_bounds(2, 3, 3, 4));
    EXPECT_FALSE(in_bounds(-1, 0, 3, 4));
    EXPECT_FALSE(in_bounds(0, -1, 3, 4));
    EXPECT_FALSE(in_bounds(3, 0, 3, 4));
    EXPECT_FALSE(in_bounds(0, 4, 3, 4));
}

TEST(StationAverage, CalculatesAverage) {
    const double temps[] = {10, 20, 30, 40, 50, 60};
    double average = 0;

    EXPECT_TRUE(station_average(temps, 2, 3, 0, average));
    EXPECT_DOUBLE_EQ(average, 20.0);

    EXPECT_TRUE(station_average(temps, 2, 3, 1, average));
    EXPECT_DOUBLE_EQ(average, 50.0);
}

TEST(StationAverage, KeepsOutputWhenInvalid) {
    const double temps[] = {10, 20, 30};
    double average = 123.0;

    EXPECT_FALSE(station_average(temps, 1, 3, -1, average));
    EXPECT_DOUBLE_EQ(average, 123.0);

    EXPECT_FALSE(station_average(temps, 1, 0, 0, average));
    EXPECT_DOUBLE_EQ(average, 123.0);
}

TEST(DayAverage, CalculatesAverage) {
    const double temps[] = {10, 20, 30, 40, 50, 60};
    double average = 0;

    EXPECT_TRUE(day_average(temps, 2, 3, 1, average));
    EXPECT_DOUBLE_EQ(average, 35.0);
}

TEST(DayAverage, KeepsOutputWhenInvalid) {
    const double temps[] = {10, 20, 30};
    double average = 123.0;

    EXPECT_FALSE(day_average(temps, 1, 3, 3, average));
    EXPECT_DOUBLE_EQ(average, 123.0);

    EXPECT_FALSE(day_average(temps, 0, 3, 0, average));
    EXPECT_DOUBLE_EQ(average, 123.0);
}

TEST(FindHottest, FindsHighestReading) {
    const double temps[] = {10, 20, 30, 90, 40, 50};
    int row = -1;
    int col = -1;

    EXPECT_TRUE(find_hottest(temps, 2, 3, row, col));
    EXPECT_EQ(row, 1);
    EXPECT_EQ(col, 0);
}

TEST(FindHottest, KeepsFirstReadingOnTie) {
    const double temps[] = {10, 90, 30, 90, 40, 50};
    int row = -1;
    int col = -1;

    EXPECT_TRUE(find_hottest(temps, 2, 3, row, col));
    EXPECT_EQ(row, 0);
    EXPECT_EQ(col, 1);
}

TEST(FindHottest, HandlesEmptyGrid) {
    const double temps[] = {10};
    int row = 7;
    int col = 8;

    EXPECT_FALSE(find_hottest(temps, 0, 0, row, col));
    EXPECT_EQ(row, 7);
    EXPECT_EQ(col, 8);
}

TEST(CountAbove, CountsStrictlyAbove) {
    const double temps[] = {90, 95, 96, 100, 80, 95};

    EXPECT_EQ(count_above(temps, 2, 3, 95.0), 2);
    EXPECT_EQ(count_above(temps, 2, 3, 100.0), 0);
    EXPECT_EQ(count_above(temps, 0, 3, 95.0), 0);
}

TEST(FindStation, FindsExactName) {
    const Station stations[] = {
        {"Denton", 642.0},
        {"Waco", 470.0}
    };

    const Station* result = find_station(stations, 2, "Waco");

    ASSERT_NE(result, nullptr);
    EXPECT_EQ(result->name, "Waco");
    EXPECT_DOUBLE_EQ(result->elevation_ft, 470.0);
}

TEST(FindStation, ReturnsNullForMissingName) {
    const Station stations[] = {
        {"Denton", 642.0},
        {"Waco", 470.0}
    };

    EXPECT_EQ(find_station(stations, 2, "Austin"), nullptr);
    EXPECT_EQ(find_station(stations, 2, "waco"), nullptr);
    EXPECT_EQ(find_station(stations, 0, "Waco"), nullptr);
}
