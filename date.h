#ifndef DATE_H
#define DATE_H
typedef struct date date_t;
/*date bitmasks*/
#define DAYM ((uint32_t) 0x1Fu)
#define MONM ((uint32_t) 0x1E0u)
#define YRM (~((uint32_t) 0x1FFu))
#define BCE BIT_SHIFT(31, 1u)
/** structure contains an unsigned 32 bit integer that stores 
 * the day in 5 bits, the month in 4 bits, and the year in the
 * rest except the last bit is reserved for CE or BCE designation
 */
struct date{

    uint32_t datecontainer;
    date(uint8_t day, uint8_t month, uint32_t year, bool bce);
    private: int setday(uint8_t day);
    private: int setmnth(uint8_t month);
    private: int setyr(uint32_t year);
    private: int setbce(bool bce);
};
#endif
