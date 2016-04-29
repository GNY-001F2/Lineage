/* date.cpp; reference implementation for a date class
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

#include "date.h"
namespace date {
    
/* constructs the date from the input date string
 * string rawdate - the date in the format [CE/BCE]-YYYY-MM-DD
 */
date_t::date_t(std::string rawdate): datecontainer(0u) {
    
    validate(rawdate);
    uint8_t day = 0u, month = 0u;
    uint32_t year = 0u;
    /*TODO: take the rawdate string and convert it into its constituent parts*/
    //implementation here
    /*TODO: call the setter functions*/
    setday(day);
    setmnth(month);
    setyr(year);
    /*TODO: validate the date*/
//     validate(datecontainer);

}

/* sets the day bits in datecontainer
 * uint8_t day - the day
 * does not return anything
 */
void date_t::setday(uint8_t day) {
    
    if (day == 0u) day++;
    uint32_t day32 = static_cast<uint32_t>(day);
    datecontainer = day32;
    return;
}

/* sets the month bits in datecontainer
 * uint8_t mnth - the month
 * does not return anything
 */
void date_t::setmnth(uint8_t month) {
    
    if (month == 0u) month++;
    uint32_t mnth32 = static_cast<uint32_t>(month) << 4;
    datecontainer |= mnth32;
    return;
}

/* sets the year bits in datecontainer
 * uint32_t year - the year
 * does not return anything
 */
void date_t::setyr(uint32_t year) {
    
    if (year == 0u) year++;
    datecontainer |= static_cast<uint32_t>(year) << 8;
    /*TODO: implement code to set year as leap year */
    return;
}

/* sets if the date happened before common era or is in the common era
 * bool bce - true means CE, false means BCE
 * does not return anything
 */
void date_t::setbce(bool bce) {
    
    uint32_t bce32 = static_cast<uint32_t>(bce) << 30;
    datecontainer |= bce32;
    return;
}

/* checks if the string is correctly entered
 * 
 */
int date_t::validate(std::string rawdate) {
    /*TODO: check if the date is being constructed correctly*/
    //if date string is ill-formed, throw exception
    return stoi(rawdate); //placeholder
}

void date_t::validate(uint32_t datecontainer) {
    
    /* since, we are only concerned with the values stored in the first
     * 30 bits we can safely ignore the BCE bit in the validation
     */
    if ((datecontainer | BAN_DATE) != BAN_DATE)
        datecontainer |= DATE_VALID;
    /*TODO: code to check validity of the date and month bits*/
    return;
}
}
