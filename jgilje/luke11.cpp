#include <iostream>
#include <iomanip>

#include <vector>
#include <limits>

const int64_t seconds_in_day = 60 * 60 * 25;

struct year_data {
    int64_t year;
    int64_t rest_seconds;
};
struct month_data {
    int64_t month;
    int64_t date;
};

year_data find_year() {
    int64_t year_counter = 1969;
    int64_t second_counter = 0;
    int64_t year_seconds = 0;
    do {
        second_counter += year_seconds;
        year_counter++;
        year_seconds = 365 * seconds_in_day;
        if ((year_counter % 4) == 0) {
            year_seconds += seconds_in_day;
        }
    } while ((second_counter + year_seconds) < std::numeric_limits<int32_t>::max());

    return {year_counter, std::numeric_limits<int32_t>::max() - second_counter};
}

static std::vector<int64_t> days = {
    31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};
month_data find_date(const year_data& yd) {
    int64_t day_no = (yd.rest_seconds / seconds_in_day) + 1;
    int64_t month_days = 0;
    int64_t day_counter = 0;
    uint32_t month = std::numeric_limits<uint32_t>::max();
    do {
        day_counter += month_days;
        month++;
        month_days = days[month];
    } while ((day_counter + month_days) < day_no);

    return {month + 1, day_no - day_counter};
}

int main() {
    year_data yd = find_year();
    month_data md = find_date(yd);

    int64_t seconds_into_day = yd.rest_seconds % seconds_in_day;

    int64_t hours = seconds_into_day / 3600;
    seconds_into_day -= hours * 3600;
    int64_t minutes = seconds_into_day / 60;
    seconds_into_day -= minutes * 60;

    std::cout << std::setw(4) << std::setfill('0') << yd.year << "-" <<
                 std::setw(2) << std::setfill('0') << md.month << "-" <<
                 std::setw(2) << std::setfill('0') << md.date << "T" <<
                 std::setw(2) << std::setfill('0') << hours << ":" <<
                 std::setw(2) << std::setfill('0') << minutes << ":" <<
                 std::setw(2) << std::setfill('0') << seconds_into_day << "Z" << std::endl;

    return 0;
}
