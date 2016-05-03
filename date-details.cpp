/* date-details.cpp; implementation details for functions called in date.cpp
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

#include "date-details.h"

namespace date {
namespace details {
void setday(uint32_t day, uint32_t* datecontainer_ptr) {
    
    if (day == 0u) day++;
    * datecontainer_ptr = day;
    return;
}

void setmnth(uint32_t month, uint32_t* datecontainer_ptr) {
    
    if (month == 0u) month++;
    * datecontainer_ptr |= month << 4;
    return;
}

void setyr(uint32_t year, uint32_t* datecontainer_ptr) {
    
    if (year == 0u) year++;
    * datecontainer_ptr |= year << 8;
    /*TODO: implement code to set year as leap year */
    return;
}

void setbce(bool bce, uint32_t* datecontainer_ptr) {
    
    uint32_t bce32 = (bce==true)?1u:0u << 30;
    * datecontainer_ptr |= bce32;
    return;
}

/* checks if the string is correctly entered */
// int date_t::validate(std::string rawdate) {
//     /*TODO: check if the date is being constructed correctly*/
//     //if date string is ill-formed, throw exception
//     return stoi(rawdate); //placeholder
// }
}
}
