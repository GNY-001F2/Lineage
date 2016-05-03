/* date-details.h; headers for the implemented parts in date-details.cpp
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

#ifndef DATE_DETAILS_H
#define DATE_DETAILS_H

#include <cinttypes>

namespace date {
namespace details {

/** sets the day bits in datecontainer
 * uint8_t day - the day
 * does not return anything
 */
void setday(uint32_t day, uint32_t* datecontainer_ptr);

/** sets the month bits in datecontainer
 * uint8_t mnth - the month
 * does not return anything
 */
void setmnth(uint32_t month, uint32_t* datecontainer_ptr);

/** sets the year bits in datecontainer
 * uint32_t year - the year
 * does not return anything
 */
void setyr(uint32_t year, uint32_t* datecontainer_ptr);

/** sets if the date happened before common era or is in the common era
 * bool bce - true means CE, false means BCE
 * does not return anything
 */
void setbce(bool bce, uint32_t* datecontainer_ptr);

}
}

#endif
