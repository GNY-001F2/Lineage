#include<string>
#include<cinttypes>
#include<bitset>

#ifndef DATET
#define DATET
typedef struct date date_t;
struct date{

    std::bitset<5> date;  //date <= 31
    std::bitset<4> month; //month <= 12 < 15
    int16_t year;

    int set_d(unsigned date);
    int set_m(unsigned month);
    int set_y(int16_t year);
};
#endif

#ifndef DYNASTY
#define DYNASTY
struct dynasty {
    std::string dname;
    person_t* founder;
    date_t founddate;
    
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

typedef struct person person_t;
struct person {
//  dynasty;
    date_t dob;
    date_t deathdate;
    uint16_t status;
    std::string givenname;
    std::string middlenames;
    std::string surname;
    person_t* father;
    person_t* realfather;
    person_t* mother;
    person_t* spouse;
    person_t* formerpartners;
    person_t* children;
    person_t* lovers;
    person_t* concubines;
    
    person(date_t dob, uint16_t status, )
    
    int set_dob(person_t* newperson);
    int set_deathdate(person_t* newperson);

    int set_name(person_t* newperson, std::string firstname, std::string lastname);
//     int set_dynasty(person_t* newperson, dynasty);
    int set_parents(person_t* newperson, person_t* father, person_t* mother);
    int add_child(person_t* parent, person_t* newperson);

    int marry(person_t* husband, person_t* wife, char marrtype);
    int add_lover(person_t* man, person_t* woman);
    int add_concubine(person_t* man, person_t* woman);

    int add_former_partner(person_t* man, person_t* woman);

    int divorce(person_t* formerhusband, person_t* formerwife);
    int set_aside_concubine(person_t* man, person_t* woman);
    int break_up(person_t* man, person_t* woman);
};
#endif
