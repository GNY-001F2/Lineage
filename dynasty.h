/* date.h; definitions for the dynasty structure
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

#ifndef LINEAGE_DYNASTY_H
#define LINEAGE_DYNASTY_H
#include <string>
#include <vector>
#include <cinttypes>
#include <memory>
#include "date.h"

namespace lineage {
//defined in person.h
namespace person {
typedef struct person_t person_t;
}

namespace dynasty {
typedef uint16_t dynid_t;
typedef struct dynasty_t {
    
    std::string dname;
    dynid_t dynid;
    std::weak_ptr<person::person_t> founder;
    date::date_t founddate;
    std::vector<std::weak_ptr<dynasty_t>> cadet_branches;
    dynasty_t(std::string dname, dynid_t dynid,
              std::weak_ptr<person::person_t> founder, date::date_t founddate);
} dynasty_t;
}
}
#endif
