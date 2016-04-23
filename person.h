#include<string>
#include<cinttypes>
#include<bitset>

#ifndef PERSONHTYPEDEFS
#define PERSONHTYPEDEFS
/* need ids to prevent person and lowborn dynasty aliasing */
typedef uint16_t dynid_t;
typedef uint64_t personid_t;
typedef struct person person_t;
typedef struct date date_t;
typedef struct dynasty dynasty_t;
#endif

#ifndef DATE
#define DATE
struct date{

    int32_t datecontainer;
    date(int32_t rawdate);
};
#endif

#ifndef DYNASTY
#define DYNASTY
struct dynasty {
    
    std::string dname;
    dynid_t dynid;
    person_t* founder;
    date_t founddate;
    
    dynasty(std::string dname, dynid_t dynid, person_t* founder,
            date_t founddate);
    ~dynasty();
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

struct person {
    
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
    
    person(dynasty_t dynasty, date_t dob, uint16_t status, person_t* mother);
    person(dynasty_t dynasty, date_t dob, uint16_t status,
           person_t* father, person_t* mother);
    person(dynasty_t dynasty, date_t dob, uint16_t status,
           person_t* father, person_t* realfather, person_t* mother);
    ~person();
};
#endif

#ifndef PERSONFNS
#define PERSONFNS

#endif
