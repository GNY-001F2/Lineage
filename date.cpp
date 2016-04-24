#include "date.h"
namespace date {
date_t::date_t(std::string rawdate) {
    
    datecontainer = 0u;
    /*TODO: take the rawdate string and convert it into its constituent parts*/
    //implementation here
    /*TODO: call the setter functions*/
//     setday(day);
//     setmtnh(month);
//     setyr(yr);
    /*TODO: validate the date*/
//     validate(datecontainer);

}
void date_t::setday(uint8_t day) {
    
    uint32_t day32 = (uint32_t) day;
    datecontainer = day32;
    return;
}
void date_t::setmnth(uint8_t month) {
    
    uint32_t mnth32 = static_cast<uint32_t>(month) << 4;
    datecontainer |= mnth32;
    return;
}
void date_t::setyr(uint32_t year) {
    
    datecontainer |= static_cast<uint32_t>(year) << 8;
    /*TODO: implement code to set year as leap year */
    return;
}
void date_t::setbce(unsigned char bce) {
    
    uint32_t bce32 = static_cast<uint32_t>(bce) << 30;
    datecontainer |= bce32;
    return;
}
void date_t::validate(uint32_t datecontainer) {
    
    /* since, we are only concerned with the values stored in the first
     * 30 bits we can safely ignore the BCE bit in the validation
     */
    if ((datecontainer | BAN_DATE) != BAN_DATE)
        datecontainer |= DATE_VALID;
    /*TODO: code to check validity of the date and month bits*/
    return;
}
}
