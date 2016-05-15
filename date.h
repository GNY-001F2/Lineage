/* date.h; definitions for the date structure
 * Copyright (C) 2016  Aayush Agarwal
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef DATE_H
#define DATE_H

#include <cinttypes>
#include <string>
#include <memory>
#include <array>

namespace date {

/** date_t contains an unsigned 32 bit integer that stores the year in bits
 * 0 to 15, the month in bits 16 to 19, day in bits 20 to 24 the leap year
 * status in bit 25, CE or BCE designation is stored in bit 26 and date
 * validity in bit 31. The remaining bits are left to the user of this class
 * to use for their own purposes.
 *
 * data members:
 *
 * uint32_t datecontainer - Stores the date with above specification
 *
 * constructors:
 *
 * date_t(uint32_t datecontainer) - Sets datecontainer with the value of
 * rawdate, with a default of 0. this constructor should call validity()
 * to set the valid bit, and throw an exception if the date is invalid
 * and the default value of 0u is not used. An object constructed with
 * the value 0u should initialize this structure correctly with
 * one of the date_init() methods.
 *
 * methods:
 *
 * int date_init() - Collection of functions to initialize the date structure
 *
 ** (std::string ISO_date, std::string era = "CE", bool suppressinval = false
 * std::string delimiter = '-') initialize directly from an ISO 8061 format
 * date string
 *
 ** (uint32_t rawyr, uint32_t rawmnth, uint32_t rawday, std::string era = "CE",
 * bool suppressinval = false) initialize by supplying numeric values for date
 * month and year
 *
 ** (uint32_t rawdate, bool suppressinval = false) similar to calling the
 * constructor, but it lets the calling program/function ignore the validity
 * of the entered date value.
 *
 *** bool suppressinval suppresses the date validity check, and is false by
 * default. However it does not suppress the setting of the valid bit.
 *
 * void validate() - checks if the date entered is valid or not. handling
 * invalidation is left to the user
 * std::string get_ISO_date() - returns the date in an ISO 8061 format string
 * std::array<std::string, 2> get_ISO_date_and_Era() - returns a string array
 * with the first element containing the era the second an ISO 8061 format date
 * and another the era. Example: {"1987-04-22", "CE"}
 */

// typedef struct date_t date_t;
typedef struct date_t {

    uint32_t datecontainer;

    date_t(uint32_t datecontainer = 0u);

    int date_init(std::string ISO_date, std::string era = "CE",
                  bool suppressinval = false, std::string delimiter = '-');
    int date_init(uint32_t rawyr, uint32_t rawmnth, uint32_t rawday,
                  std::string era = "CE", bool suppressinval = false);
    int date_init(uint32_t rawdate, bool suppressinval = false);
//     void setday(uint8_t day);
//     void setmnth(uint8_t month);
//     void setyr(uint32_t year);
//     void setbce(bool bce);
//     int validate(std::string rawdate);

public:
    void validate(bool suppressinval = false);
    std::string get_ISO_date();
    std::array<std::string, 2> get_ISO_date_and_era();

} date_t;

}

#endif
