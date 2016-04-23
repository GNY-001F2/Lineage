#include<string>
#include<cinttypes>
#include<bitset>
#include "date.h"

#ifndef TYPEDEFS
#define TYPEDEFS
/* forward declaration for stuff that fails to compile */
typedef struct person_t person_t;
#endif

#ifndef DYNASTY
#define DYNASTY
typedef uint16_t dynid_t;
typedef struct dynasty_t dynasty_t;
struct dynasty_t {
    
    std::string dname;
    dynid_t dynid;
    person_t* founder;
    date_t founddate;
    
    dynasty_t(std::string dname, dynid_t dynid, person_t* founder,
            date_t founddate);
};
#endif

#ifndef PERSON_H
#define PERSON_H
/* status bitmasks */
#define ISALIVE 0x1u
#define ISMALE 0x2u
#define ISMARRIED 0x4u
#define INMATMARR 0x8u
#define ISDIVORCED 0x10u
#define ISPREGNANT 0x20u
#define HASCONCUBINES 0x40u
#define HASLOVERS 0x80u
#define FMRPARTNERS 0x100u
#define ISBASTARD 0x200u
#define KNWNBASTARD 0x400u
#define ISLGTMZD 0x800u
#define ISLOWBORN 0x1000u
#define ISADULT 0x2000u

typedef uint64_t personid_t;
struct person_t {
    
    dynasty_t* dynasty;
    personid_t pid;
    date_t dob;
    date_t deathdate;
    uint16_t status;
    std::string givenname;
    std::string middlenames;
    std::string surname;
    person_t* father;
    person_t* realfather; //for bastards
    person_t* mother;
    person_t* spouse;
    person_t* formerpartners;
    person_t* children;
    person_t* lovers;
    person_t* concubines;
    
    person_t(dynasty_t dynasty, std::string rawdob, uint16_t status, person_t* mother);
    person_t(dynasty_t dynasty, std::string rawdob, uint16_t status,
           person_t* father, person_t* mother);
    person_t(dynasty_t dynasty, std::string rawdob, uint16_t status,
           person_t* father, person_t* realfather, person_t* mother);
};
#endif

#ifndef PERSONFNS
#define PERSONFNS

#endif
