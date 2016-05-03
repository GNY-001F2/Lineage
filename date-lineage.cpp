/* extensions for the lineage project */
namespace lineage {
namespace date {
    //needed for game timekeeping
    void increment(std::weak_ptr<::date::date_t> datecontainer,
                   std::string currdate);
}
}
 
