#include "Common.h"
#include <string>
#include <array>

struct TaxiNodeEntry
{
    uint32    id = 0;
    uint32    build = 0;
    uint32    map_id = 0;
    float x = 0;
    float y = 0;
    float z = 0;
    std::string name;
    uint32 mount_creature_id1 = 0;
    uint32 mount_creature_id2 = 0;

    bool operator==(const TaxiNodeEntry& val) const
    {
        return (id == val.id) &&
            (map_id == val.map_id) &&
            (x == val.x) &&
            (y == val.y) &&
            (z == val.z) &&
            (name == val.name) &&
            (mount_creature_id1 == val.mount_creature_id1) &&
            (mount_creature_id2 == val.mount_creature_id2);
    }

    bool operator<(const TaxiNodeEntry& val) const
    {
        if (id == val.id)
            return build < val.build;

        return id < val.id;
    }
};