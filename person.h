#ifndef PERSON_H
#define PERSON_H

#include<string>
// #include "dynasty"

/* status bits */
#define ISALIVE 0x1u
#define ISMALE 0x2u
#define ISMARRIED 0x4u
#define INMATMARR 0x8u //matrilineal marriage
#define ISDIVORCED 0x10u
#define ISPREGNANT 0x20u
#define HASCONCUBINES 0x40u
#define HASLOVERS 0x80u
#define HASPARTNERS 0x100u
#define ISBASTARD 0x200u
#define ISLGTMZD 0x400u

typedef struct date date;
struct date{
private:
    unsigned char date[3];
    
public:
    int set_d(person* newperson);
    int set_m(person* newperson);
    int set_y(person* newperson);
};

typedef struct status status;
struct status{
    unsigned char status[2];
};

typedef struct person person;
struct person {

private:
//  dynasty;
    date dob;
    date deathdate;
    status personstat;
    std::string givenname;
    std::string middlenames;
    std::string surname;
    person* father;
    person* mother;
    person* spouse;
    person* formerpartners;
    person* children;
    person* lovers;
    person* concubines;
    
public:
    int set_dob(person* newperson);
    int set_deathdate(person* newperson);

    int set_name(person* newperson, std::string firstname, std::string lastname);
//     int set_dynasty(person* newperson, dynasty);
    int set_parents(person* newperson, person* father, person* mother);
    int add_child(person* parent, person* newperson);

    int marry(person* husband, person* wife, char marrtype);
    int add_lover(person* man, person* woman);
    int add_concubine(person* man, person* woman);

    int add_former_partner(person* man, person* woman);

    int divorce(person* formerhusband, person* formerwife);
    int set_aside_concubine(person* man, person* woman);
    int break_up(person* man, person* woman);
};
#endif
