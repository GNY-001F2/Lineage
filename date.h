#ifndef DATE_H
#define DATE_H
#include<cinttypes>
#include<string>
/*date bitmasks*/
#define DAYM ((uint32_t) 0x1Fu)
#define MONM ((uint32_t) 0x1E0u)
#define YRM (~((uint32_t) 0x1FFu))
/* since, we are only concerned with the values stored in the first
 * 30 bits we can safely ignore the BCE bit in the validation*/
#define BAN_DATE (~((uint32_t) 0x7FFFFFFFu))
#define DATE_VALID (1 << 31)
/** structure contains an unsigned 32 bit integer that stores 
 * the day in 5 bits, the month in the next 4 bits.
 * leap year designation set in the 30th bit.
 * all bits between these reserved bits can be used to store a year.
 * CE or BCE designation is stored in the 31st bit.
 * Date validity is stored in the 32nd bit.
 */
namespace date {
typedef struct date_t date_t;
struct date_t {

    uint32_t datecontainer;
    date_t(std::string rawdate);
    private: void setday(uint8_t day);
    private: void setmnth(uint8_t month);
    private: void setyr(uint32_t year);
    private: void setbce(unsigned char bce);
    private: void validate(uint32_t datecontainer);
};
}
#endif
