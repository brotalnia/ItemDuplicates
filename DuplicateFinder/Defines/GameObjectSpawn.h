#include "Common.h"

struct GameObjectSpawn
{
    uint32    guid = 0;
	uint32    id;
	uint32    map;
	float     position_x;
	float     position_y;
	float     position_z;
	float     orientation;
	float     rotation0;
	float     rotation1;
	float     rotation2;
	float     rotation3;

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