#ifndef LINEAGE_PERSON_H
#define LINEAGE_PERSON_H

#include <string>
#include <cinttypes>
#include <bitset>
#include <memory>
#include <vector>
#include "date.h"

namespace person {
/* forward declaration for stuff that otherwise fails to compile */
typedef struct person_t person_t;
typedef struct maleperson_t maleperson_t;
typedef struct femaleperson_t femaleperson_t;

typedef uint16_t dynid_t;
typedef struct dynasty_t dynasty_t;
struct dynasty_t {
    
    std::string dname;
    dynid_t dynid;
    std::shared_ptr<person_t> founder;
    date::date_t founddate;
    
    dynasty_t(std::string dname, dynid_t dynid, std::shared_ptr<person_t> founder,
            date::date_t founddate);
};

/* common status bitmasks */
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

typedef uint64_t personid_t;
struct person_t {
    
    std::shared_ptr<dynasty_t> dynasty;
    personid_t pid;
    date::date_t dob;
    date::date_t deathdate;
    uint16_t status;
    std::string givenname;
    std::string middlenames;
    std::string surname;
    std::shared_ptr<maleperson_t> father;
    std::shared_ptr<maleperson_t> realfather; //for bastards
    std::shared_ptr<femaleperson_t> mother;
    std::shared_ptr<person_t> spouse;
    std::vector<std::shared_ptr<person_t>> formerpartners;
    std::vector<std::shared_ptr<person_t>> children;
    std::vector<std::shared_ptr<person_t>> lovers;
    
    person_t(dynasty_t dynasty, std::string rawdob, uint16_t status, std::shared_ptr<person_t> mother);
    person_t(dynasty_t dynasty, std::string rawdob, uint16_t status,
           std::shared_ptr<person_t> father, std::shared_ptr<person_t> mother);
    person_t(dynasty_t dynasty, std::string rawdob, uint16_t status,
           std::shared_ptr<person_t> father, std::shared_ptr<person_t> realfather, std::shared_ptr<person_t> mother);
};

#define ISADULTER 0x800u
#define HASCONCUBINES 0x1000u
struct maleperson_t : public person_t {
    std::vector<std::shared_ptr<person_t>> concubines;
};

#define ISADULTERESS 0x800u
#define ISPREGNANT 0x1000u
struct femaleperson_t : public person_t {};
}

#endif
