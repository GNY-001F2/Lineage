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
