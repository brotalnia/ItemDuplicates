#include "Common.h"
#include <array>

#define MAX_ITEM_PROTO_DAMAGES 5
#define MAX_ITEM_PROTO_SPELLS  5
#define MAX_ITEM_PROTO_STATS 10

struct _Damage
{
    float   DamageMin = 0;
    float   DamageMax = 0;
    uint32  DamageType = 0;                                     // id from Resistances.dbc

    bool operator==(const _Damage& val) const
    {
        return (DamageMin == val.DamageMin) && (DamageMax == val.DamageMax) && (DamageType == val.DamageType);
    }
};

struct _ItemStat
{
    uint32  ItemStatType = 0;
    int32   ItemStatValue = 0;

    bool operator==(const _ItemStat& val) const
    {
        return (ItemStatType == val.ItemStatType) && (ItemStatValue == val.ItemStatValue);
    }
};
struct _Spell
{
    uint32 SpellId = 0;                                         // id from Spell.dbc
    uint32 SpellTrigger = 0;
    int32  SpellCharges = 0;
    float  SpellPPMRate = 0;
    int32  SpellCooldown = 0;
    uint32 SpellCategory = 0;                                   // id from SpellCategory.dbc
    int32  SpellCategoryCooldown = 0;

    bool operator==(const _Spell& val) const
    {
        return (SpellId == val.SpellId) && (SpellTrigger == val.SpellTrigger) && (SpellCharges == val.SpellCharges) && (SpellPPMRate == val.SpellPPMRate) && (SpellCooldown == val.SpellCooldown) && (SpellCategory == val.SpellCategory) && (SpellCategoryCooldown == val.SpellCategoryCooldown);
    }
};

struct ItemTemplate
{

    bool operator<(const ItemTemplate& val) const
    {
        if (Entry == val.Entry)
            return Patch < val.Patch;

        return Entry < val.Entry;
    }

    bool operator==(const ItemTemplate& val) const
    {
        return (Entry == val.Entry) &&
            (Class == val.Class) &&
            (SubClass == val.SubClass) &&
            (Name == val.Name) &&
            (Description == val.Description) &&
            (DisplayInfoID == val.DisplayInfoID) &&
            (Quality == val.Quality) &&
            (Flags == val.Flags) &&
            (BuyCount == val.BuyCount) &&
            (BuyPrice == val.BuyPrice) &&
            (SellPrice == val.SellPrice) &&
            (InventoryType == val.InventoryType) &&
            (AllowableClass == val.AllowableClass) &&
            (AllowableRace == val.AllowableRace) &&
            (ItemLevel == val.ItemLevel) &&
            (RequiredLevel == val.RequiredLevel) &&
            (RequiredSkill == val.RequiredSkill) &&
            (RequiredSkillRank == val.RequiredSkillRank) &&
            (RequiredSpell == val.RequiredSpell) &&
            (RequiredHonorRank == val.RequiredHonorRank) &&
            (RequiredCityRank == val.RequiredCityRank) &&
            (RequiredReputationFaction == val.RequiredReputationFaction) &&
            (RequiredReputationRank == val.RequiredReputationRank) &&
            (MaxCount == val.MaxCount) &&
            (Stackable == val.Stackable) &&
            (ContainerSlots == val.ContainerSlots) &&
            (ItemStat == val.ItemStat) &&
            (Delay == val.Delay) &&
            (RangedModRange == val.RangedModRange) &&
            (AmmoType == val.AmmoType) &&
            (Damage == val.Damage) &&
            (Block == val.Block) &&
            (Armor == val.Armor) &&
            (HolyRes == val.HolyRes) &&
            (FireRes == val.FireRes) &&
            (NatureRes == val.NatureRes) &&
            (FrostRes == val.FrostRes) &&
            (ShadowRes == val.ShadowRes) &&
            (ArcaneRes == val.ArcaneRes) &&
            (Spells == val.Spells) &&
            (Bonding == val.Bonding) &&
            (PageText == val.PageText) &&
            (LanguageID == val.LanguageID) &&
            (PageMaterial == val.PageMaterial) &&
            (StartQuest == val.StartQuest) &&
            (LockID == val.LockID) &&
            (Material == val.Material) &&
            (Sheath == val.Sheath) &&
            (RandomProperty == val.RandomProperty) &&
            (ItemSet == val.ItemSet) &&
            (MaxDurability == val.MaxDurability) &&
            (Area == val.Area) &&
            (Map == val.Map) &&
            (Duration == val.Duration) &&
            (BagFamily == val.BagFamily) &&
            (DisenchantID == val.DisenchantID) &&
            (FoodType == val.FoodType) &&
            (MinMoneyLoot == val.MinMoneyLoot) &&
            (MaxMoneyLoot == val.MaxMoneyLoot) &&
            (ExtraFlags == val.ExtraFlags);
    }

    uint32 Entry;
    uint32 Patch;
    uint32 Class;                                           // id from ItemClass.dbc
    uint32 SubClass;                                        // id from ItemSubClass.dbc
    std::string  Name;
    std::string  Description;
    uint32 DisplayInfoID;                                   // id from ItemDisplayInfo.dbc
    uint32 Quality;
    uint32 Flags;
    uint32 BuyCount;
    uint32 BuyPrice;
    uint32 SellPrice;
    uint32 InventoryType;
    uint32 AllowableClass;
    uint32 AllowableRace;
    uint32 ItemLevel;
    uint32 RequiredLevel;
    uint32 RequiredSkill;                                   // id from SkillLine.dbc
    uint32 RequiredSkillRank;
    uint32 RequiredSpell;                                   // id from Spell.dbc
    uint32 RequiredHonorRank;
    uint32 RequiredCityRank;
    uint32 RequiredReputationFaction;                       // id from Faction.dbc
    uint32 RequiredReputationRank;
    uint32 MaxCount;
    uint32 Stackable;
    uint32 ContainerSlots;
    std::array<_ItemStat, MAX_ITEM_PROTO_STATS>  ItemStat;
    uint32 Delay;
    float  RangedModRange;
    uint32 AmmoType;
    std::array<_Damage, MAX_ITEM_PROTO_DAMAGES> Damage;
    uint32 Block;
    int32 Armor;
    int32 HolyRes;
    int32 FireRes;
    int32 NatureRes;
    int32 FrostRes;
    int32 ShadowRes;
    int32 ArcaneRes;
    std::array<_Spell, MAX_ITEM_PROTO_SPELLS> Spells;
    uint32 Bonding;
    uint32 PageText;
    uint32 LanguageID;
    uint32 PageMaterial;
    uint32 StartQuest;                                      // id from QuestCache.wdb
    uint32 LockID;
    uint32 Material;                                        // id from Material.dbc
    uint32 Sheath;
    uint32 RandomProperty;                                  // id from ItemRandomProperties.dbc
    uint32 ItemSet;                                         // id from ItemSet.dbc
    uint32 MaxDurability;
    uint32 Area;                                            // id from AreaTable.dbc
    uint32 Map;                                             // id from Map.dbc
    uint32 Duration;
    uint32 BagFamily;
    uint32 DisenchantID;
    uint32 FoodType;
    uint32 MinMoneyLoot;
    uint32 MaxMoneyLoot;
    uint32 ExtraFlags;
};