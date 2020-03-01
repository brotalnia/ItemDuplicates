// This tool finds duplicated database entries.
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
#include "Defines\SpellTemplate.h"
#include "Defines\FactionEntry.h"
#include "Defines\TaxiNodeEntry.h"
#include "Defines\GameObjectSpawn.h"

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

void CheckItems()
{
    std::ofstream myfile("item_duplicates.sql");
    if (!myfile.is_open())
        return;

    std::set<ItemTemplate> itemsData;

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

            itemsData.insert(item);
        } while (result->NextRow());
    }

    printf("Loaded %u item templates.\n", itemsData.size());

    for (auto it = itemsData.begin(); it != itemsData.end(); it++)
    {
        auto next_item = std::next(it, 1);

        if (next_item == itemsData.end())
            break;

        if ((*it) == (*next_item))
        {
            printf("Duplicate of entry %u for patch %u.\n", next_item->Entry, next_item->Patch);
            myfile << "DELETE FROM `item_template` WHERE `entry`=" << next_item->Entry << " && `patch`=" << next_item->Patch << ";\n";
        }
    }
    myfile.close();
}

void CheckFactions()
{
    std::ofstream myfile("faction_duplicates.sql");
    if (!myfile.is_open())
        return;

    std::set<FactionEntry> factionsData;

    printf("Loading faction database.\n");
    //                                                              0     1        2                     3                      4                      5                      6                      7                       8                       9                       10                      11                 12                 13                 14                 15                   16                   17                   18                   19      20      21              
    if (std::shared_ptr<QueryResult> result = GameDb.Query("SELECT `id`, `build`, `reputation_list_id`, `base_rep_race_mask1`, `base_rep_race_mask2`, `base_rep_race_mask3`, `base_rep_race_mask4`, `base_rep_class_mask1`, `base_rep_class_mask2`, `base_rep_class_mask3`, `base_rep_class_mask4`, `base_rep_value1`, `base_rep_value2`, `base_rep_value3`, `base_rep_value4`, `reputation_flags1`, `reputation_flags2`, `reputation_flags3`, `reputation_flags4`, `team`, `name`, `description` FROM `faction` ORDER BY `id`, `build`"))
    {
        do
        {
            DbField* pFields = result->fetchCurrentRow();

            FactionEntry faction;

            faction.id = pFields[0].getUInt32();
            faction.build = pFields[1].getUInt32();
            faction.reputation_list_id = pFields[2].getInt32();
            faction.base_rep_race_mask[0] = pFields[3].getUInt32();
            faction.base_rep_race_mask[1] = pFields[4].getUInt32();
            faction.base_rep_race_mask[2] = pFields[5].getUInt32();
            faction.base_rep_race_mask[3] = pFields[6].getUInt32();
            faction.base_rep_class_mask[0] = pFields[7].getUInt32();
            faction.base_rep_class_mask[1] = pFields[8].getUInt32();
            faction.base_rep_class_mask[2] = pFields[9].getUInt32();
            faction.base_rep_class_mask[3] = pFields[10].getUInt32();
            faction.base_rep_value[0] = pFields[11].getInt32();
            faction.base_rep_value[1] = pFields[12].getInt32();
            faction.base_rep_value[2] = pFields[13].getInt32();
            faction.base_rep_value[3] = pFields[14].getInt32();
            faction.reputation_flags[0] = pFields[15].getUInt32();
            faction.reputation_flags[1] = pFields[16].getUInt32();
            faction.reputation_flags[2] = pFields[17].getUInt32();
            faction.reputation_flags[3] = pFields[18].getUInt32();
            faction.team = pFields[19].getUInt32();
            faction.name = pFields[20].getCppString();
            faction.description = pFields[21].getCppString();

            factionsData.insert(faction);
        } while (result->NextRow());
    }

    printf("Loaded %u faction templates.\n", factionsData.size());

    for (auto it = factionsData.begin(); it != factionsData.end(); it++)
    {
        auto next_item = std::next(it, 1);

        if (next_item == factionsData.end())
            break;

        if ((*it) == (*next_item))
        {
            printf("Duplicate of entry %u for build %u.\n", next_item->id, next_item->build);
            myfile << "DELETE FROM `faction` WHERE `id`=" << next_item->id << " && `build`=" << next_item->build << ";\n";
        }
    }
    myfile.close();
}

void CheckTaxiNodes()
{
    std::ofstream myfile("taxi_node_duplicates.sql");
    if (!myfile.is_open())
        return;

    std::set<TaxiNodeEntry> taxiData;

    printf("Loading taxi node database.\n");
    //                                                              0     1        2         3    4    5    6       7                    8            
    if (std::shared_ptr<QueryResult> result = GameDb.Query("SELECT `id`, `build`, `map_id`, `x`, `y`, `z`, `name`, `mount_creature_id1`, `mount_creature_id2` FROM `taxi_nodes` ORDER BY `id`, `build`"))
    {
        do
        {
            DbField* pFields = result->fetchCurrentRow();

            TaxiNodeEntry node;

            node.id = pFields[0].getUInt32();
            node.build = pFields[1].getUInt32();
            node.map_id = pFields[2].getUInt32();
            node.x = pFields[3].getFloat();
            node.y = pFields[4].getFloat();
            node.z = pFields[5].getFloat();
            node.name = pFields[6].getCppString();
            node.mount_creature_id1 = pFields[7].getUInt32();
            node.mount_creature_id2 = pFields[8].getUInt32();

            taxiData.insert(node);
        } while (result->NextRow());
    }

    printf("Loaded %u taxi nodes.\n", taxiData.size());

    for (auto it = taxiData.begin(); it != taxiData.end(); it++)
    {
        auto next_item = std::next(it, 1);

        if (next_item == taxiData.end())
            break;

        if ((*it) == (*next_item))
        {
            printf("Duplicate of entry %u for build %u.\n", next_item->id, next_item->build);
            myfile << "DELETE FROM `taxi_nodes` WHERE `id`=" << next_item->id << " && `build`=" << next_item->build << ";\n";
        }
    }
    myfile.close();
}


void CheckSpells()
{
    std::ofstream myfile("spell_duplicates.sql");
    if (!myfile.is_open())
        return;

    std::set<SpellEntry> spellsData;

    printf("Loading spell database.\n");
    //                                                              0      1      2       3         4       5       6         7           8             9              10             11             12       13          14       15                  16                  17               18               19                20            21                    22              23                  24                     25         26          27           28        29         30          31             32         33        34               35             36                     37          38     39              40           41      42      43        44        45        46        47        48        49        50        51             52             53             54             55             56             57             58             59                 60                        61                             62       63       64       65               66               67               68               69               70               71                   72                   73                   74                         75                         76                         77                 78                 79                 80               81               82               83                      84                      85                      86                      87                      88                      89                  90                  91                  92                    93                    94                    95                96                97                98                    99                    100                   101                 102                 103                 104              105              106              107               108               109               110                  111                  112                  113                         114                         115                         116           117           118          119           120            121   122        123          124               125          126               127              128                  129                  130                    131                132             133             134              135               136                 137       138             139             140             141             142             143           144            145                 146
    if (std::shared_ptr<QueryResult> result = GameDb.Query("SELECT  entry, build, school, category, castUI, dispel, mechanic, attributes, attributesEx, attributesEx2, attributesEx3, attributesEx4, stances, stancesNot, targets, targetCreatureType, requiresSpellFocus, casterAuraState, targetAuraState, castingTimeIndex, recoveryTime, categoryRecoveryTime, interruptFlags, auraInterruptFlags, channelInterruptFlags, procFlags, procChance, procCharges, maxLevel, baseLevel, spellLevel, durationIndex, powerType, manaCost, manCostPerLevel, manaPerSecond, manaPerSecondPerLevel, rangeIndex, speed, modelNextSpell, stackAmount, totem1, totem2, reagent1, reagent2, reagent3, reagent4, reagent5, reagent6, reagent7, reagent8, reagentCount1, reagentCount2, reagentCount3, reagentCount4, reagentCount5, reagentCount6, reagentCount7, reagentCount8, equippedItemClass, equippedItemSubClassMask, equippedItemInventoryTypeMask, effect1, effect2, effect3, effectDieSides1, effectDieSides2, effectDieSides3, effectBaseDice1, effectBaseDice2, effectBaseDice3, effectDicePerLevel1, effectDicePerLevel2, effectDicePerLevel3, effectRealPointsPerLevel1, effectRealPointsPerLevel2, effectRealPointsPerLevel3, effectBasePoints1, effectBasePoints2, effectBasePoints3, effectMechanic1, effectMechanic2, effectMechanic3, effectImplicitTargetA1, effectImplicitTargetA2, effectImplicitTargetA3, effectImplicitTargetB1, effectImplicitTargetB2, effectImplicitTargetB3, effectRadiusIndex1, effectRadiusIndex2, effectRadiusIndex3, effectApplyAuraName1, effectApplyAuraName2, effectApplyAuraName3, effectAmplitude1, effectAmplitude2, effectAmplitude3, effectMultipleValue1, effectMultipleValue2, effectMultipleValue3, effectChainTarget1, effectChainTarget2, effectChainTarget3, effectItemType1, effectItemType2, effectItemType3, effectMiscValue1, effectMiscValue2, effectMiscValue3, effectTriggerSpell1, effectTriggerSpell2, effectTriggerSpell3, effectPointsPerComboPoint1, effectPointsPerComboPoint2, effectPointsPerComboPoint3, spellVisual1, spellVisual2, spellIconId, activeIconId, spellPriority, name, nameFlags, nameSubtext, nameSubtextFlags, description, descriptionFlags, auraDescription, auraDescriptionFlags, manaCostPercentage, startRecoveryCategory, startRecoveryTime, minTargetLevel, maxTargetLevel, spellFamilyName, spellFamilyFlags, maxAffectedTargets, dmgClass, preventionType, stanceBarOrder, dmgMultiplier1, dmgMultiplier2, dmgMultiplier3, minFactionId, minReputation, requiredAuraVision, customFlags FROM spell_template ORDER BY entry, build"))
    {
        do
        {
            DbField* fields = result->fetchCurrentRow();
            
            SpellEntry spell;
            
            spell.entry = fields[0].getUInt32();
            spell.build = fields[1].getUInt32();
            spell.school = fields[2].getUInt32();
            spell.category = fields[3].getUInt32();
            spell.castUI = fields[4].getUInt32();
            spell.dispel = fields[5].getUInt32();
            spell.mechanic = fields[6].getUInt32();
            spell.attributes = fields[7].getUInt32();
            spell.attributesEx = fields[8].getUInt32();
            spell.attributesEx2 = fields[9].getUInt32();
            spell.attributesEx3 = fields[10].getUInt32();
            spell.attributesEx4 = fields[11].getUInt32();
            spell.stances = fields[12].getUInt32();
            spell.stancesNot = fields[13].getUInt32();
            spell.targets = fields[14].getUInt32();
            spell.targetCreatureType = fields[15].getUInt32();
            spell.requiresSpellFocus = fields[16].getUInt32();
            spell.casterAuraState = fields[17].getUInt32();
            spell.targetAuraState = fields[18].getUInt32();
            spell.castingTimeIndex = fields[19].getUInt32();
            spell.recoveryTime = fields[20].getUInt32();
            spell.categoryRecoveryTime = fields[21].getUInt32();
            spell.interruptFlags = fields[22].getUInt32();
            spell.auraInterruptFlags = fields[23].getUInt32();
            spell.channelInterruptFlags = fields[24].getUInt32();
            spell.procFlags = fields[25].getUInt32();
            spell.procChance = fields[26].getUInt32();
            spell.procCharges = fields[27].getUInt32();
            spell.maxLevel = fields[28].getUInt32();
            spell.baseLevel = fields[29].getUInt32();
            spell.spellLevel = fields[30].getUInt32();
            spell.durationIndex = fields[31].getUInt32();
            spell.powerType = fields[32].getUInt32();
            spell.manaCost = fields[33].getUInt32();
            spell.manaCostPerlevel = fields[34].getUInt32();
            spell.manaPerSecond = fields[35].getUInt32();
            spell.manaPerSecondPerLevel = fields[36].getUInt32();
            spell.rangeIndex = fields[37].getUInt32();
            spell.speed = fields[38].getFloat();
            spell.modalNextSpell = fields[39].getUInt32();
            spell.stackAmount = fields[40].getUInt32();
            spell.totem[0] = fields[41].getUInt32();
            spell.totem[1] = fields[42].getUInt32();
            spell.reagent[0] = fields[43].getInt32();
            spell.reagent[1] = fields[44].getInt32();
            spell.reagent[2] = fields[45].getInt32();
            spell.reagent[3] = fields[46].getInt32();
            spell.reagent[4] = fields[47].getInt32();
            spell.reagent[5] = fields[48].getInt32();
            spell.reagent[6] = fields[49].getInt32();
            spell.reagent[7] = fields[50].getInt32();
            spell.reagentCount[0] = fields[51].getUInt32();
            spell.reagentCount[1] = fields[52].getUInt32();
            spell.reagentCount[2] = fields[53].getUInt32();
            spell.reagentCount[3] = fields[54].getUInt32();
            spell.reagentCount[4] = fields[55].getUInt32();
            spell.reagentCount[5] = fields[56].getUInt32();
            spell.reagentCount[6] = fields[57].getUInt32();
            spell.reagentCount[7] = fields[58].getUInt32();
            spell.equippedItemClass = fields[59].getInt32();
            spell.equippedItemSubClassMask = fields[60].getInt32();
            spell.equippedItemInventoryTypeMask = fields[61].getInt32();
            spell.effect[0] = fields[62].getUInt32();
            spell.effect[1] = fields[63].getUInt32();
            spell.effect[2] = fields[64].getUInt32();
            spell.effectDieSides[0] = fields[65].getInt32();
            spell.effectDieSides[1] = fields[66].getInt32();
            spell.effectDieSides[2] = fields[67].getInt32();
            spell.effectBaseDice[0] = fields[68].getUInt32();
            spell.effectBaseDice[1] = fields[69].getUInt32();
            spell.effectBaseDice[2] = fields[70].getUInt32();
            spell.effectDicePerLevel[0] = fields[71].getFloat();
            spell.effectDicePerLevel[1] = fields[72].getFloat();
            spell.effectDicePerLevel[2] = fields[73].getFloat();
            spell.effectRealPointsPerLevel[0] = fields[74].getFloat();
            spell.effectRealPointsPerLevel[1] = fields[75].getFloat();
            spell.effectRealPointsPerLevel[2] = fields[76].getFloat();
            spell.effectBasePoints[0] = fields[77].getInt32();
            spell.effectBasePoints[1] = fields[78].getInt32();
            spell.effectBasePoints[2] = fields[79].getInt32();
            spell.effectMechanic[0] = fields[80].getUInt32();
            spell.effectMechanic[1] = fields[81].getUInt32();
            spell.effectMechanic[2] = fields[82].getUInt32();
            spell.effectImplicitTargetA[0] = fields[83].getUInt32();
            spell.effectImplicitTargetA[1] = fields[84].getUInt32();
            spell.effectImplicitTargetA[2] = fields[85].getUInt32();
            spell.effectImplicitTargetB[0] = fields[86].getUInt32();
            spell.effectImplicitTargetB[1] = fields[87].getUInt32();
            spell.effectImplicitTargetB[2] = fields[88].getUInt32();
            spell.effectRadiusIndex[0] = fields[89].getUInt32();
            spell.effectRadiusIndex[1] = fields[90].getUInt32();
            spell.effectRadiusIndex[2] = fields[91].getUInt32();
            spell.effectApplyAuraName[0] = fields[92].getUInt32();
            spell.effectApplyAuraName[1] = fields[93].getUInt32();
            spell.effectApplyAuraName[2] = fields[94].getUInt32();
            spell.effectAmplitude[0] = fields[95].getUInt32();
            spell.effectAmplitude[1] = fields[96].getUInt32();
            spell.effectAmplitude[2] = fields[97].getUInt32();
            spell.effectMultipleValue[0] = fields[98].getFloat();
            spell.effectMultipleValue[1] = fields[99].getFloat();
            spell.effectMultipleValue[2] = fields[100].getFloat();
            spell.effectChainTarget[0] = fields[101].getUInt32();
            spell.effectChainTarget[1] = fields[102].getUInt32();
            spell.effectChainTarget[2] = fields[103].getUInt32();
            spell.effectItemType[0] = fields[104].getUInt32();
            spell.effectItemType[1] = fields[105].getUInt32();
            spell.effectItemType[2] = fields[106].getUInt32();
            spell.effectMiscValue[0] = fields[107].getInt32();
            spell.effectMiscValue[1] = fields[108].getInt32();
            spell.effectMiscValue[2] = fields[109].getInt32();
            spell.effectTriggerSpell[0] = fields[110].getUInt32();
            spell.effectTriggerSpell[1] = fields[111].getUInt32();
            spell.effectTriggerSpell[2] = fields[112].getUInt32();
            spell.effectPointsPerComboPoint[0] = fields[113].getFloat();
            spell.effectPointsPerComboPoint[1] = fields[114].getFloat();
            spell.effectPointsPerComboPoint[2] = fields[115].getFloat();
            spell.spellVisual = fields[116].getUInt32();
            spell.spellVisual2 = fields[117].getUInt32();
            spell.spellIconId = fields[118].getUInt32();
            spell.activeIconID = fields[119].getUInt32();
            spell.spellPriority = fields[120].getUInt32();
            spell.name = fields[121].getCppString();
            spell.nameFlags = fields[122].getUInt32();
            spell.nameSubtext = fields[123].getCppString();
            spell.nameSubtextFlags = fields[124].getUInt32();
            spell.description = fields[125].getCppString();
            spell.descriptionFlags = fields[126].getUInt32();
            spell.auraDescription = fields[127].getCppString();
            spell.auraDescriptionFlags = fields[128].getUInt32();
            spell.manaCostPercentage = fields[129].getUInt32();
            spell.startRecoveryCategory = fields[130].getUInt32();
            spell.startRecoveryTime = fields[131].getUInt32();
            spell.minTargetLevel = fields[132].getUInt32();
            spell.maxTargetLevel = fields[133].getUInt32();
            spell.spellFamilyName = fields[134].getUInt32();
            spell.spellFamilyFlags = fields[135].getUInt64();
            spell.maxAffectedTargets = fields[136].getUInt32();
            spell.dmgClass = fields[137].getUInt32();
            spell.preventionType = fields[138].getUInt32();
            spell.stanceBarOrder = fields[139].getInt32();
            spell.dmgMultiplier[0] = fields[140].getFloat();
            spell.dmgMultiplier[1] = fields[141].getFloat();
            spell.dmgMultiplier[2] = fields[142].getFloat();
            spell.minFactionId = fields[143].getUInt32();
            spell.minReputation = fields[144].getUInt32();
            spell.requiredAuraVision = fields[145].getUInt32();
            spell.customFlags = fields[146].getUInt32();
            
            spellsData.insert(spell);
        } while (result->NextRow());
    }

    printf("Loaded %u spell templates.\n", spellsData.size());
    std::unordered_map<uint32 /*build*/, std::set<uint32> /*entries*/> entriesToDelete;

    for (auto it = spellsData.begin(); it != spellsData.end(); it++)
    {
        auto next_item = std::next(it, 1);

        if (next_item == spellsData.end())
            break;
        
        if ((*it) == (*next_item))
        {
            printf("Duplicate of entry %u for build %u.\n", next_item->entry, next_item->build);
            entriesToDelete[next_item->build].insert(next_item->entry);
        }
    }

    for (const auto& build : entriesToDelete)
    {
        if (build.second.empty())
            continue;
        myfile << "DELETE FROM `spell_template` WHERE `build`=" << build.first << " && `entry` IN (";
        uint32 count = 0;
        for (const auto entry : build.second)
        {
            if (count > 0)
                myfile << ", ";
            myfile << entry;
            count++;
        }
        myfile << ");\n";
    }

    myfile.close();
}

void CheckGameobjectSpawns()
{
    std::ofstream myfile("gameobject_spawn_duplicates.sql");
    if (!myfile.is_open())
        return;

    std::vector<GameObjectSpawn> goSpawnData;

    printf("Loading gameobject spawn database.\n");
    //                                                              0       1     2      3             4             5             6              7            8            9            10
    if (std::shared_ptr<QueryResult> result = GameDb.Query("SELECT `guid`, `id`, `map`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3` FROM `gameobject` ORDER BY `guid`"))
    {
        do
        {
            DbField* pFields = result->fetchCurrentRow();

            GameObjectSpawn spawn;

            spawn.guid = pFields[0].getUInt32();
            spawn.id = pFields[1].getUInt32();
            spawn.map = pFields[2].getUInt32();
            spawn.position_x = pFields[3].getFloat();
            spawn.position_y = pFields[4].getFloat();
            spawn.position_z = pFields[5].getFloat();
            spawn.orientation = pFields[6].getFloat();
            spawn.rotation0 = pFields[7].getFloat();
            spawn.rotation1 = pFields[8].getFloat();
            spawn.rotation2 = pFields[9].getFloat();
            spawn.rotation3 = pFields[10].getFloat();

            goSpawnData.push_back(spawn);
        } while (result->NextRow());
    }

    printf("Loaded %u gameobject spawns.\n", goSpawnData.size());

    for (uint32 i = 0; i < goSpawnData.size(); i++)
    {
        for (uint32 j = i + 1; j < goSpawnData.size(); j++)
        {
            if (goSpawnData[i] == goSpawnData[j])
            {
                printf("Duplicate of guid %u found.\n", goSpawnData[i].guid);
                myfile << "DELETE FROM `gameobject` WHERE `guid`=" << goSpawnData[j].guid << ";\n";
                goSpawnData.erase(goSpawnData.begin() + j);
                j--;
            }
        }
    }
    myfile.close();
}

int main()
{
    printf("\nEnter your database connection info.\n");
    std::string const connection_string = MakeConnectionString();

    printf("\nConnecting to database.\n");
    if (!GameDb.Initialize(connection_string.c_str()))
    {
        printf("\nError: Cannot connect to world database!\n");
        return 1;
    }

    printf("Select table to check for duplicates:\n");
    printf("1. item_template\n");
    printf("2. spell_template\n");
    printf("3. faction\n");
    printf("4. taxi_nodes\n");
    printf("5. gameobject\n");

    char option = getchar();
    switch (option)
    {
        case '1':
            CheckItems();
            break;
        case '2':
            CheckSpells();
            break;
        case '3':
            CheckFactions();
            break;
        case '4':
            CheckTaxiNodes();
            break;
        case '5':
            CheckGameobjectSpawns();
            break;
    }

    printf("Done.\n");
    system("pause");

    GameDb.Uninitialise();
    return 0;
}

