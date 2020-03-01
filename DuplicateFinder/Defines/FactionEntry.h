#include "Common.h"
#include <string>
#include <array>

struct FactionEntry
{
    uint32    id = 0;
    uint32    build = 0;
    int32    reputation_list_id = 0;
    std::array<uint32, 4>    base_rep_race_mask = {};
    std::array<uint32, 4>    base_rep_class_mask = {};
    std::array<int32, 4>    base_rep_value = {};
    std::array<uint32, 4>    reputation_flags = {};
    uint32    team = 0;
    std::string    name;
    std::string    description;
    
    bool operator==(const FactionEntry& val) const
    {
        return (id == val.id) &&
            (reputation_list_id == val.reputation_list_id) &&
            (base_rep_race_mask == val.base_rep_race_mask) &&
            (base_rep_class_mask == val.base_rep_class_mask) &&
            (base_rep_value == val.base_rep_value) &&
            (reputation_flags == val.reputation_flags) &&
            (team == val.team) &&
            (name == val.name) &&
            (description == val.description);
    }

    bool operator<(const FactionEntry& val) const
    {
        if (id == val.id)
            return build < val.build;

        return id < val.id;
    }
};