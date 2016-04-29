/* date.h; definitions for the date structure
 * Copyright (C) 2016  Aayush Agarwal
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef DATE_H
#define DATE_H

#include <cinttypes>
#include <string>
#include <memory>

/*date bitmasks*/
#define DAYM ((uint32_t) 0x1Fu)
#define MONM ((uint32_t) 0x1E0u)
#define YRM (~((uint32_t) 0x1FFu))
#define BAN_DATE (~((uint32_t) 0x7FFFFFFFu))
#define DATE_VALID (1 << 31)

namespace date {

/** structure contains an unsigned 32 bit integer that stores 
 * the day in 5 bits, the month in the next 4 bits.
 * leap year designation set in the 30th bit.
 * all bits between these reserved bits can be used to store a year.
 * CE or BCE designation is stored in the 31st bit.
 * Date validity is stored in the 32nd bit.
 */
typedef struct date_t date_t;
struct date_t {

    uint32_t datecontainer;
    date_t(std::string rawdate);

private:
    void setday(uint8_t day);
    void setmnth(uint8_t month);
    void setyr(uint32_t year);
    void setbce(bool bce);
    int validate(std::string rawdate);
    void validate(uint32_t datecontainer);
    
friend
    void increment(std::weak_ptr<date_t> datecontainer, std::string currdate);
};

//needed for game clock
void increment(std::weak_ptr<date_t> datecontainer, std::string currdate);
}

#endif
