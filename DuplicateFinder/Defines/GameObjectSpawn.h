#include "Common.h"

struct GameObjectSpawn
{
    uint32    guid = 0;
    uint32    id = 0;
    uint32    map = 0;
	float     position_x = 0.0f;
	float     position_y = 0.0f;
	float     position_z = 0.0f;
	float     orientation = 0.0f;
	float     rotation0 = 0.0f;
	float     rotation1 = 0.0f;
	float     rotation2 = 0.0f;
    float     rotation3 = 0.0f;

    bool operator==(const GameObjectSpawn& val) const
    {
        return (id == val.id) &&
               (map == val.map) &&
			   (position_x == val.position_x) &&
               (position_y == val.position_y) &&
               (position_z == val.position_z) &&
               (orientation == val.orientation) &&
               (rotation0 == val.rotation0) &&
               (rotation1 == val.rotation1) &&
               (rotation2 == val.rotation2) &&
               (rotation3 == val.rotation3);
    }

    bool operator<(const GameObjectSpawn& val) const
    {
        return guid < val.guid;
    }
};