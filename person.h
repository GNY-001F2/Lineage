#ifndef LINEAGE_PERSON_H
#define LINEAGE_PERSON_H

#include <string>
#include <cinttypes>
#include <memory>
#include <vector>
#include "date.h"

//defined in dynasty.h

namespace lineage {
namespace dynasty {
typedef struct dynasty_t dynasty_t;
}
}

/* common status bitmasks */
#define RESET 0x0u
#define ISALIVE 0x1u
#define ISMARRIED 0x2u
#define INMATMARR 0x4u
#define ISDIVORCED 0x8u
#define HASLOVERS 0x10u
#define FMRPARTNERS 0x20u
#define ISBASTARD 0x40u
#define KNWNBASTARD 0x80u
#define ISLGTMZD 0x100u
#define ISLOWBORN 0x200u
#define ISADULT 0x400u
#define ISCHEATR 0x800u
#define KNWNCHTR 0x1000u
#define ISHOMOSEXUAL 0x2000u

/* male bitmasks */
#define HASCONCUBINES 0x4000u

/* female bitmasks */
#define ISPREGNANT 0x4000u

namespace lineage {
namespace person {
/* forward declaration for stuff that otherwise fails to compile */
typedef struct maleperson_t maleperson_t;
typedef struct femaleperson_t femaleperson_t;

typedef uint64_t personid_t;
typedef uint8_t age_t;
typedef struct person_t {
    
    std::shared_ptr<dynasty::dynasty_t> dynasty;
    personid_t pid;
    date::date_t dob;
    date::date_t deathdate;
    uint16_t status;
    std::string givenname;
    std::string middlenames;
    std::string surname;
    age_t age;
    std::weak_ptr<maleperson_t> father;
    std::weak_ptr<maleperson_t> realfather; //for bastards
    std::weak_ptr<femaleperson_t> mother;
    std::weak_ptr<person_t> spouse;
    std::vector<std::shared_ptr<person_t>> formerpartners;
    std::vector<std::shared_ptr<person_t>> children;
    std::vector<std::shared_ptr<person_t>> lovers;

    person_t(dynasty::dynasty_t dynasty, std::string rawdob, uint16_t status,
             std::shared_ptr<person_t> realfather,
             std::shared_ptr<person_t> mother);
//     person_t(dynasty_t dynasty, std::string rawdob, uint16_t status,
//            std::shared_ptr<person_t> father, std::shared_ptr<person_t> mother);
    person_t(dynasty::dynasty_t dynasty, std::string rawdob, uint16_t status,
             std::shared_ptr<person_t> father,
             std::shared_ptr<person_t> realfather,
             std::shared_ptr<person_t> mother);
} person_t;


struct maleperson_t : public person_t {
    std::vector<std::shared_ptr<person_t>> concubines;
};

struct femaleperson_t : public person_t {
    std::vector<std::shared_ptr<person_t>> pregnantwith;
    std::vector<std::shared_ptr<person_t>> bastards;
};
}
}
#endif
