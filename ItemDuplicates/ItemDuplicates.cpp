// This tool finds duplicated item template entries.
// Author: brotalnia
//

#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <array>
#include <set>

#include "Database\Database.h"
#include "Defines\ItemTemplate.h"

Database GameDb;

std::string MakeConnectionString()
{
    std::string mysql_host;
    std::string mysql_port;
    std::string mysql_user;
    std::string mysql_pass;
    std::string mysql_db;

    printf("Host: ");
    getline(std::cin, mysql_host);
    if (mysql_host.empty())
        mysql_host = "127.0.0.1";

    printf("Port: ");
    getline(std::cin, mysql_port);
    if (mysql_port.empty())
        mysql_port = "3306";

    printf("User: ");
    getline(std::cin, mysql_user);
    if (mysql_user.empty())
        mysql_user = "root";

    printf("Password: ");
    getline(std::cin, mysql_pass);
    if (mysql_pass.empty())
        mysql_pass = "root";

    printf("Database: ");
    getline(std::cin, mysql_db);
    if (mysql_db.empty())
        mysql_db = "mangos";

    return mysql_host + ";" + mysql_port + ";" + mysql_user + ";" + mysql_pass + ";" + mysql_db;
}

bool IsNumber(const std::string &s) {
    return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
}

int main()
{
    std::ofstream myfile("item_duplicates.sql");
    if (!myfile.is_open())
        return 1;

    printf("\nEnter your database connection info.\n");
    std::string const connection_string = MakeConnectionString();

    printf("\nConnecting to database.\n");
    if (!GameDb.Initialize(connection_string.c_str()))
    {
        printf("\nError: Cannot connect to world database!\n");
        getchar();
        return 1;
    }

    std::set<ItemTemplate> ItemsData;

    printf("Loading item database.\n");
    //                                                              0        1        2        3           4       5              6             7          8        9            10           11            12                13                 14                15            16                17                18                     19                20                     21                    22                             23                          24           25           26                 27            28             29            30            31             32            33             34            35             36           37              38             39            40             41            42             43            44             45            46               47       48           49           50          51          52           53          54          55           56          57          58           59          60          61           62          63          64           65       66       67          68          69            70           71            72            73           74                75                76                77                 78                 79                         80           81                82                83                84                 85                 86                         87           88                89                90                91                 92                 93                         94           95                96                97                98                 99                 100                        101          102               103               104               105                106                107                        108        109          110              111              112            113        114         115       116                117       118               119           120          121         122           123              124          125               126               127               
    if (std::shared_ptr<QueryResult> result = GameDb.Query("SELECT `entry`, `patch`, `class`, `subclass`, `name`, `description`, `display_id`, `quality`, `flags`, `buy_count`, `buy_price`, `sell_price`, `inventory_type`, `allowable_class`, `allowable_race`, `item_level`, `required_level`, `required_skill`, `required_skill_rank`, `required_spell`, `required_honor_rank`, `required_city_rank`, `required_reputation_faction`, `required_reputation_rank`, `max_count`, `stackable`, `container_slots`, `stat_type1`, `stat_value1`, `stat_type2`, `stat_value2`, `stat_type3`, `stat_value3`, `stat_type4`, `stat_value4`, `stat_type5`, `stat_value5`, `stat_type6`, `stat_value6`, `stat_type7`, `stat_value7`, `stat_type8`, `stat_value8`, `stat_type9`, `stat_value9`, `stat_type10`, `stat_value10`, `delay`, `range_mod`, `ammo_type`, `dmg_min1`, `dmg_max1`, `dmg_type1`, `dmg_min2`, `dmg_max2`, `dmg_type2`, `dmg_min3`, `dmg_max3`, `dmg_type3`, `dmg_min4`, `dmg_max4`, `dmg_type4`, `dmg_min5`, `dmg_max5`, `dmg_type5`, `block`, `armor`, `holy_res`, `fire_res`, `nature_res`, `frost_res`, `shadow_res`, `arcane_res`, `spellid_1`, `spelltrigger_1`, `spellcharges_1`, `spellppmrate_1`, `spellcooldown_1`, `spellcategory_1`, `spellcategorycooldown_1`, `spellid_2`, `spelltrigger_2`, `spellcharges_2`, `spellppmrate_2`, `spellcooldown_2`, `spellcategory_2`, `spellcategorycooldown_2`, `spellid_3`, `spelltrigger_3`, `spellcharges_3`, `spellppmrate_3`, `spellcooldown_3`, `spellcategory_3`, `spellcategorycooldown_3`, `spellid_4`, `spelltrigger_4`, `spellcharges_4`, `spellppmrate_4`, `spellcooldown_4`, `spellcategory_4`, `spellcategorycooldown_4`, `spellid_5`, `spelltrigger_5`, `spellcharges_5`, `spellppmrate_5`, `spellcooldown_5`, `spellcategory_5`, `spellcategorycooldown_5`, `bonding`, `page_text`, `page_language`, `page_material`, `start_quest`, `lock_id`, `material`, `sheath`, `random_property`, `set_id`, `max_durability`, `area_bound`, `map_bound`, `duration`, `bag_family`, `disenchant_id`, `food_type`, `min_money_loot`, `max_money_loot`, `extra_flags` FROM `item_template`"))
    {
        do
        {
            DbField* pFields = result->fetchCurrentRow();

            ItemTemplate item;

            item.Entry = pFields[0].getUInt32();
            item.Patch = pFields[1].getUInt8();
            item.Class = pFields[2].getUInt8();
            item.SubClass = pFields[3].getUInt8();
            item.Name = pFields[4].getCppString();
            item.Description = pFields[5].getCppString();
            item.DisplayInfoID = pFields[6].getUInt32();
            item.Quality = pFields[7].getUInt32();
            item.Flags = pFields[8].getUInt32();
            item.BuyCount = pFields[9].getUInt32();
            item.BuyPrice = pFields[10].getUInt32();
            item.SellPrice = pFields[11].getUInt32();
            item.InventoryType = pFields[12].getUInt32();
            item.AllowableClass = pFields[13].getUInt32();
            item.AllowableRace = pFields[14].getUInt32();
            item.ItemLevel = pFields[15].getUInt32();
            item.RequiredLevel = pFields[16].getUInt32();
            item.RequiredSkill = pFields[17].getUInt32();
            item.RequiredSkillRank = pFields[18].getUInt32();
            item.RequiredSpell = pFields[19].getUInt32();
            item.RequiredHonorRank = pFields[20].getUInt32();
            item.RequiredCityRank = pFields[21].getUInt32();
            item.RequiredReputationFaction = pFields[22].getUInt32();
            item.RequiredReputationRank = pFields[23].getUInt32();
            item.MaxCount = pFields[24].getUInt32();
            item.Stackable = pFields[25].getUInt32();
            item.ContainerSlots = pFields[26].getUInt32();
            item.ItemStat[0].ItemStatType = pFields[27].getUInt32();
            item.ItemStat[0].ItemStatValue = pFields[28].getUInt32();
            item.ItemStat[1].ItemStatType = pFields[29].getUInt32();
            item.ItemStat[1].ItemStatValue = pFields[30].getUInt32();
            item.ItemStat[2].ItemStatType = pFields[31].getUInt32();
            item.ItemStat[2].ItemStatValue = pFields[32].getUInt32();
            item.ItemStat[3].ItemStatType = pFields[33].getUInt32();
            item.ItemStat[3].ItemStatValue = pFields[34].getUInt32();
            item.ItemStat[4].ItemStatType = pFields[35].getUInt32();
            item.ItemStat[4].ItemStatValue = pFields[36].getUInt32();
            item.ItemStat[5].ItemStatType = pFields[37].getUInt32();
            item.ItemStat[5].ItemStatValue = pFields[38].getUInt32();
            item.ItemStat[6].ItemStatType = pFields[39].getUInt32();
            item.ItemStat[6].ItemStatValue = pFields[40].getUInt32();
            item.ItemStat[7].ItemStatType = pFields[41].getUInt32();
            item.ItemStat[7].ItemStatValue = pFields[42].getUInt32();
            item.ItemStat[8].ItemStatType = pFields[43].getUInt32();
            item.ItemStat[8].ItemStatValue = pFields[44].getUInt32();
            item.ItemStat[9].ItemStatType = pFields[45].getUInt32();
            item.ItemStat[9].ItemStatValue = pFields[46].getUInt32();
            item.Delay = pFields[47].getUInt32();
            item.RangedModRange = pFields[48].getFloat();
            item.AmmoType = pFields[49].getUInt32();
            item.Damage[0].DamageMin = pFields[50].getFloat();
            item.Damage[0].DamageMax = pFields[51].getFloat();
            item.Damage[0].DamageType = pFields[52].getUInt32();
            item.Damage[1].DamageMin = pFields[53].getFloat();
            item.Damage[1].DamageMax = pFields[54].getFloat();
            item.Damage[1].DamageType = pFields[55].getUInt32();
            item.Damage[2].DamageMin = pFields[56].getFloat();
            item.Damage[2].DamageMax = pFields[57].getFloat();
            item.Damage[2].DamageType = pFields[58].getUInt32();
            item.Damage[3].DamageMin = pFields[59].getFloat();
            item.Damage[3].DamageMax = pFields[60].getFloat();
            item.Damage[3].DamageType = pFields[61].getUInt32();
            item.Damage[4].DamageMin = pFields[62].getFloat();
            item.Damage[4].DamageMax = pFields[63].getFloat();
            item.Damage[4].DamageType = pFields[64].getUInt32();
            item.Block = pFields[65].getUInt32();
            item.Armor = pFields[66].getUInt32();
            item.HolyRes = pFields[67].getUInt32();
            item.FireRes = pFields[68].getUInt32();
            item.NatureRes = pFields[69].getUInt32();
            item.FrostRes = pFields[70].getUInt32();
            item.ShadowRes = pFields[71].getUInt32();
            item.ArcaneRes = pFields[72].getUInt32();
            item.Spells[0].SpellId = pFields[73].getUInt32();
            item.Spells[0].SpellTrigger = pFields[74].getUInt32();
            item.Spells[0].SpellCharges = pFields[75].getUInt32();
            item.Spells[0].SpellPPMRate = pFields[76].getFloat();
            item.Spells[0].SpellCooldown = pFields[77].getUInt32();
            item.Spells[0].SpellCategory = pFields[78].getUInt32();
            item.Spells[0].SpellCategoryCooldown = pFields[79].getUInt32();
            item.Spells[1].SpellId = pFields[80].getUInt32();
            item.Spells[1].SpellTrigger = pFields[81].getUInt32();
            item.Spells[1].SpellCharges = pFields[82].getUInt32();
            item.Spells[1].SpellPPMRate = pFields[83].getFloat();
            item.Spells[1].SpellCooldown = pFields[84].getUInt32();
            item.Spells[1].SpellCategory = pFields[85].getUInt32();
            item.Spells[1].SpellCategoryCooldown = pFields[86].getUInt32();
            item.Spells[2].SpellId = pFields[87].getUInt32();
            item.Spells[2].SpellTrigger = pFields[88].getUInt32();
            item.Spells[2].SpellCharges = pFields[89].getUInt32();
            item.Spells[2].SpellPPMRate = pFields[90].getFloat();
            item.Spells[2].SpellCooldown = pFields[91].getUInt32();
            item.Spells[2].SpellCategory = pFields[92].getUInt32();
            item.Spells[2].SpellCategoryCooldown = pFields[93].getUInt32();
            item.Spells[3].SpellId = pFields[94].getUInt32();
            item.Spells[3].SpellTrigger = pFields[95].getUInt32();
            item.Spells[3].SpellCharges = pFields[96].getUInt32();
            item.Spells[3].SpellPPMRate = pFields[97].getFloat();
            item.Spells[3].SpellCooldown = pFields[98].getUInt32();
            item.Spells[3].SpellCategory = pFields[99].getUInt32();
            item.Spells[3].SpellCategoryCooldown = pFields[100].getUInt32();
            item.Spells[4].SpellId = pFields[101].getUInt32();
            item.Spells[4].SpellTrigger = pFields[102].getUInt32();
            item.Spells[4].SpellCharges = pFields[103].getUInt32();
            item.Spells[4].SpellPPMRate = pFields[104].getFloat();
            item.Spells[4].SpellCooldown = pFields[105].getUInt32();
            item.Spells[4].SpellCategory = pFields[106].getUInt32();
            item.Spells[4].SpellCategoryCooldown = pFields[107].getUInt32();
            item.Bonding = pFields[108].getUInt32();
            item.PageText = pFields[109].getUInt32();
            item.LanguageID = pFields[110].getUInt32();
            item.PageMaterial = pFields[111].getUInt32();
            item.StartQuest = pFields[112].getUInt32();
            item.LockID = pFields[113].getUInt32();
            item.Material = pFields[114].getUInt32();
            item.Sheath = pFields[115].getUInt32();
            item.RandomProperty = pFields[116].getUInt32();
            item.ItemSet = pFields[117].getUInt32();
            item.MaxDurability = pFields[118].getUInt32();
            item.Area = pFields[119].getUInt32();
            item.Map = pFields[120].getUInt32();
            item.Duration = pFields[121].getUInt32();
            item.BagFamily = pFields[122].getUInt32();
            item.DisenchantID = pFields[123].getUInt32();
            item.FoodType = pFields[124].getUInt32();
            item.MinMoneyLoot = pFields[125].getUInt32();
            item.MaxMoneyLoot = pFields[126].getUInt32();
            item.ExtraFlags = pFields[127].getUInt32();

            ItemsData.insert(item);
        } while (result->NextRow());
    }

    printf("Loaded %u item templates.\n", ItemsData.size());

    for (auto it = ItemsData.begin(); it != ItemsData.end(); it++)
    {
        auto next_item = std::next(it, 1);

        if (next_item == ItemsData.end())
            break;

        if ((*it) == (*next_item))
        {
            printf("Duplicate of entry %u for patch %u.\n", next_item->Entry, next_item->Patch);
            myfile << "DELETE FROM `item_template` WHERE `entry`=" << next_item->Entry << " && `patch`=" << next_item->Patch << ";\n";
        }
    }

    printf("Done.");
    getchar();

    myfile.close();
    GameDb.Uninitialise();
    return 0;
}

