/* date.cpp; reference implementation for a date class
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

#include <vector>
#include "date.h"
#include "date-details.h"
#include "stringtokenizer.h"

/* sanitize the day, month and year values */
#define YR_SANITIZE 0xFFFFu
#define DAY_SANITIZE 0x1F00000u
#define MNTH_SANITIZE 0xFu


#define CE_BCE (0x1u << 31)
#define 

namespace date {

date_t::date_t(uint32_t datecontainer): datecontainer(datecontainer) {
}

int date_t::date_init(std::string ISO_date, std::string era,
                      bool suppressinval, std::string delimiter) {
    
    /* WARNING: Please don't enter values in the string that exceed
     * sizeof(long) on your machine. if you do they will be truncated.
     *
     * Please also do not exceed the following sizes as the extra bits will be
     * set to 0 before being added to the date:
     * year: 20 bits
     * date: 5 bits
     * month: 4 bits
     *
     * note that in this implementation if suppressinval is set to true:
     * month >= 12, it will be converted to 1 (january).
     * if day, month, or year = 0, they will be incremented by 1.
     * if the date is out of bounds in months where it should be less than 31
     * it will be changed to 1, and the month incremented by 1.
     * the year as well, if necessary.
     */
    
    std::vector<unsigned long>
    ISO_date_parts = stringtokenizer::sttoulv(ISO_date, '-');
    
    unsigned long rawyr = ISO_date_parts[0], rawmnth = ISO_date_parts[1],
    rawday = ISO_date_parts[2];
    if(suppressinval) {
        auto pospower = [](unsigned long base, int pow) -> unsigned long {
            if(base == 1u || pow == 0) return 1u;
            if(pow == 1) return base;
            unsigned long result = 1u;
            while(pow > 1) {
                if(pow % 2 != 0) {
                    result *= base;
                    pow--;
                    continue;
                }
                base *= base;
                pow /= 2;
            }
            return result * base;
        };
        if(rawyr > (pospower(2u, 20)-1u) && ) rawyr = 
    }
    
    uint32_t day = 0u, month = 0u, year = 0u;
    year = static_cast<uint32_t>(ISO_date_parts[0]);
    month = static_cast<uint32_t>(ISO_date_parts[1]);
    day = static_cast<uint32_t>(ISO_date_parts[2]);
    
    
    
    date_init(year, month,  era, suppressinval);
    
    if(year == 0u) year++;
    if(month == 0u) month++;
    if(day == 0u) day++;
    

    //implementation here
    /*TODO: call the setter functions*/
    details::setday(day, & datecontainer);
    details::setmnth(month, & datecontainer);
    details::setyr(year, & datecontainer);
    if(era == "CE") details::setbce(false, & datecontainer);
    else if(era == "BCE") details::setbce(true, & datecontainer);
    /*TODO: validate the date*/
    validate(datecontainer);

}

int date_t::date_init(uint32_t rawyr, uint32_t rawmnth, uint32_t rawdate,
                      std::string era = "CE") {
    
    /* WARNING: date_init() will not check if the raw values are correct. It
     * will only validate the final date value. The rawyr, rawmnth and rawdate
     * values will have their invalid bits set to 0 to prevent bits in 
     * datecontainer from being overwritten.
     * It is the responsibility of the function that is calling date_init() to
     * ensure that the string has correct values.
     */
    
    datecontainer |= day & DAY_SANITIZE;
    datecontainer |= month & MNTH_SANITIZE;
    datecontainer |= month & YR_SANITIZE);
}


void date_t::validate(bool throwinval) {
    
    /* since, we are only concerned with the values stored in the first
     * 30 bits we can safely ignore the BCE bit in the validation
     */
    if ((datecontainer | BAN_DATE) != BAN_DATE) datecontainer |= DATE_VALID;
    else datecontainer &= ~DATE_VALID;
    /*TODO: code to check validity of the date and month bits*/
    return;
}

/* implementation of the functions */

}

