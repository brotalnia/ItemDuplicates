#include "Common.h"
#include <string>
#include <array>

#define MAX_EFFECT_INDEX 3
#define MAX_SPELL_REAGENTS 8
#define MAX_SPELL_TOTEMS 2

struct SpellEntry
{
    uint32    entry = 0;
    uint32    build = 0;
    uint32    school = 0;
    uint32    category = 0; 
    uint32    castUI = 0;
    uint32    dispel = 0; 
    uint32    mechanic = 0; 
    uint32    attributes = 0;
    uint32    attributesEx = 0;
    uint32    attributesEx2 = 0;
    uint32    attributesEx3 = 0;
    uint32    attributesEx4 = 0;
    uint32    stances = 0;
    uint32    stancesNot = 0;
    uint32    targets = 0;
    uint32    targetCreatureType = 0;
    uint32    requiresSpellFocus = 0;
    uint32    casterAuraState = 0;
    uint32    targetAuraState = 0;
    uint32    castingTimeIndex = 0;
    uint32    recoveryTime = 0;
    uint32    categoryRecoveryTime = 0;
    uint32    interruptFlags = 0;
    uint32    auraInterruptFlags = 0;
    uint32    channelInterruptFlags = 0;
    uint32    procFlags = 0;
    uint32    procChance = 0;
    uint32    procCharges = 0;
    uint32    maxLevel = 0;
    uint32    baseLevel = 0;
    uint32    spellLevel = 0;
    uint32    durationIndex = 0;
    uint32    powerType = 0;
    uint32    manaCost = 0;
    uint32    manaCostPerlevel = 0;
    uint32    manaPerSecond = 0;
    uint32    manaPerSecondPerLevel = 0;
    uint32    rangeIndex = 1;
    float     speed = 0.f;
    uint32    modalNextSpell = 0;
    uint32    stackAmount = 0;
    std::array<uint32, MAX_SPELL_TOTEMS> totem = {};
    std::array<int32, MAX_SPELL_REAGENTS> reagent = {};
    std::array<uint32, MAX_SPELL_REAGENTS> reagentCount = {};
    int32     equippedItemClass = -1;
    int32     equippedItemSubClassMask = 0;
    int32     equippedItemInventoryTypeMask = 0;
    std::array<uint32, MAX_EFFECT_INDEX> effect = {};
    std::array<int32, MAX_EFFECT_INDEX> effectDieSides = {};
    std::array<uint32, MAX_EFFECT_INDEX> effectBaseDice = {};
    std::array<float, MAX_EFFECT_INDEX> effectDicePerLevel = {};
    std::array<float, MAX_EFFECT_INDEX> effectRealPointsPerLevel = {};
    std::array<int32, MAX_EFFECT_INDEX> effectBasePoints = {};
    std::array<uint32, MAX_EFFECT_INDEX> effectMechanic = {};
    std::array<uint32, MAX_EFFECT_INDEX> effectImplicitTargetA = {};
    std::array<uint32, MAX_EFFECT_INDEX> effectImplicitTargetB = {};
    std::array<uint32, MAX_EFFECT_INDEX> effectRadiusIndex = {};
    std::array<uint32, MAX_EFFECT_INDEX> effectApplyAuraName = {};
    std::array<uint32, MAX_EFFECT_INDEX> effectAmplitude = {};
    std::array<float, MAX_EFFECT_INDEX> effectMultipleValue = {};
    std::array<uint32, MAX_EFFECT_INDEX> effectChainTarget = {};
    std::array<uint32, MAX_EFFECT_INDEX> effectItemType = {};
    std::array<int32, MAX_EFFECT_INDEX> effectMiscValue = {};
    std::array<uint32, MAX_EFFECT_INDEX> effectTriggerSpell = {};
    std::array<float, MAX_EFFECT_INDEX> effectPointsPerComboPoint = {};
    uint32    spellVisual = 0;
    uint32    spellVisual2 = 0;
    uint32    spellIconId = 0;
    uint32    activeIconID = 0;
    uint32    spellPriority = 0;
    std::string name;
    uint32    nameFlags = 0;
    std::string nameSubtext;
    uint32    nameSubtextFlags = 0;
    std::string     description;
    uint32    descriptionFlags = 0;
    std::string     auraDescription;
    uint32    auraDescriptionFlags = 0;
    uint32    manaCostPercentage = 0;
    uint32    startRecoveryCategory = 0;
    uint32    startRecoveryTime = 0;
    uint32    minTargetLevel = 0;
    uint32    maxTargetLevel = 0;
    uint32    spellFamilyName = 0;
    uint64    spellFamilyFlags = 0;
    uint32    maxAffectedTargets = 0;
    uint32    dmgClass = 0;
    uint32    preventionType = 0;
    int32     stanceBarOrder = 0;
    std::array<float, MAX_EFFECT_INDEX> dmgMultiplier = {};
    uint32    minFactionId = 0;
    uint32    minReputation = 0;
    uint32    requiredAuraVision = 0;
    uint32    customFlags = 0;

    void compare(const SpellEntry& val) const
    {
        if (!(entry == val.entry))
            printf("entry \n");
        if (!(school == val.school))
            printf("school \n");
        if (!(category == val.category))
            printf("category \n");
        if (!(castUI == val.castUI))
            printf("castUI \n");
        if (!(dispel == val.dispel))
            printf("dispel \n");
        if (!(mechanic == val.mechanic))
            printf("mechanic \n");
        if (!(attributes == val.attributes))
            printf("attributes \n");
        if (!(attributesEx == val.attributesEx))
            printf("attributesEx \n");
        if (!(attributesEx2 == val.attributesEx2))
            printf("attributesEx2 \n");
        if (!(attributesEx3 == val.attributesEx3))
            printf("attributesEx3 \n");
        if (!(attributesEx4 == val.attributesEx4))
            printf("attributesEx4 \n");
        if (!(stances == val.stances))
            printf("stances \n");
        if (!(stancesNot == val.stancesNot))
            printf("stancesNot \n");
        if (!(targets == val.targets))
            printf("targets \n");
        if (!(targetCreatureType == val.targetCreatureType))
            printf("targetCreatureType \n");
        if (!(requiresSpellFocus == val.requiresSpellFocus))
            printf("requiresSpellFocus \n");
        if (!(casterAuraState == val.casterAuraState))
            printf("casterAuraState \n");
        if (!(targetAuraState == val.targetAuraState))
            printf("targetAuraState \n");
        if (!(castingTimeIndex == val.castingTimeIndex))
            printf("castingTimeIndex \n");
        if (!(recoveryTime == val.recoveryTime))
            printf("recoveryTime \n");
        if (!(categoryRecoveryTime == val.categoryRecoveryTime))
            printf("categoryRecoveryTime \n");
        if (!(interruptFlags == val.interruptFlags))
            printf("interruptFlags \n");
        if (!(auraInterruptFlags == val.auraInterruptFlags))
            printf("auraInterruptFlags \n");
        if (!(channelInterruptFlags == val.channelInterruptFlags))
            printf("channelInterruptFlags \n");
        if (!(procFlags == val.procFlags))
            printf("procFlags \n");
        if (!(procChance == val.procChance))
            printf("procChance \n");
        if (!(procCharges == val.procCharges))
            printf("procCharges \n");
        if (!(maxLevel == val.maxLevel))
            printf("maxLevel \n");
        if (!(baseLevel == val.baseLevel))
            printf("baseLevel \n");
        if (!(spellLevel == val.spellLevel))
            printf("spellLevel \n");
        if (!(durationIndex == val.durationIndex))
            printf("durationIndex \n");
        if (!(powerType == val.powerType))
            printf("powerType \n");
        if (!(manaCost == val.manaCost))
            printf("manaCost \n");
        if (!(manaCostPerlevel == val.manaCostPerlevel))
            printf("manaCostPerlevel \n");
        if (!(manaPerSecond == val.manaPerSecond))
            printf("manaPerSecond \n");
        if (!(manaPerSecondPerLevel == val.manaPerSecondPerLevel))
            printf("manaPerSecondPerLevel \n");
        if (!(rangeIndex == val.rangeIndex))
            printf("rangeIndex \n");
        if (!(speed == val.speed))
            printf("speed \n");
        if (!(modalNextSpell == val.modalNextSpell))
            printf("modalNextSpell \n");
        if (!(stackAmount == val.stackAmount))
            printf("stackAmount \n");
        if (!(totem == val.totem))
            printf("totem \n");
        if (!(reagent == val.reagent))
            printf("reagent \n");
        if (!(reagentCount == val.reagentCount))
            printf("reagentCount \n");
        if (!(equippedItemClass == val.equippedItemClass))
            printf("equippedItemClass \n");
        if (!(equippedItemSubClassMask == val.equippedItemSubClassMask))
            printf("equippedItemSubClassMask \n");
        if (!(equippedItemInventoryTypeMask == val.equippedItemInventoryTypeMask))
            printf("equippedItemInventoryTypeMask \n");
        if (!(effect == val.effect))
            printf("effect \n");
        if (!(effectDieSides == val.effectDieSides))
            printf("effectDieSides \n");
        if (!(effectBaseDice == val.effectBaseDice))
            printf("effectBaseDice \n");
        if (!(effectDicePerLevel == val.effectDicePerLevel))
            printf("effectDicePerLevel \n");
        if (!(effectRealPointsPerLevel == val.effectRealPointsPerLevel))
            printf("effectRealPointsPerLevel \n");
        if (!(effectBasePoints == val.effectBasePoints))
            printf("effectBasePoints \n");
        if (!(effectMechanic == val.effectMechanic))
            printf("effectMechanic \n");
        if (!(effectImplicitTargetA == val.effectImplicitTargetA))
            printf("effectImplicitTargetA \n");
        if (!(effectImplicitTargetB == val.effectImplicitTargetB))
            printf("effectImplicitTargetB \n");
        if (!(effectRadiusIndex == val.effectRadiusIndex))
            printf("effectRadiusIndex \n");
        if (!(effectApplyAuraName == val.effectApplyAuraName))
            printf("effectApplyAuraName \n");
        if (!(effectAmplitude == val.effectAmplitude))
            printf("effectAmplitude \n");
        if (!(effectMultipleValue == val.effectMultipleValue))
            printf("effectMultipleValue \n");
        if (!(effectChainTarget == val.effectChainTarget))
            printf("effectChainTarget \n");
        if (!(effectItemType == val.effectItemType))
            printf("effectItemType \n");
        if (!(effectMiscValue == val.effectMiscValue))
            printf("effectMiscValue \n");
        if (!(effectTriggerSpell == val.effectTriggerSpell))
            printf("effectTriggerSpell \n");
        if (!(effectPointsPerComboPoint == val.effectPointsPerComboPoint))
            printf("effectPointsPerComboPoint \n");
        if (!(spellVisual == val.spellVisual))
            printf("spellVisual \n");
        if (!(spellVisual2 == val.spellVisual2))
            printf("spellVisual2 \n");
        if (!(spellIconId == val.spellIconId))
            printf("spellIconId \n");
        if (!(activeIconID == val.activeIconID))
            printf("activeIconID \n");
        if (!(spellPriority == val.spellPriority))
            printf("spellPriority \n");
        if (!(name == val.name))
            printf("name \n");
        if (!(nameFlags == val.nameFlags))
            printf("nameFlags \n");
        if (!(nameSubtext == val.nameSubtext))
            printf("nameSubtext \n");
        if (!(nameSubtextFlags == val.nameSubtextFlags))
            printf("nameSubtextFlags \n");
        if (!(description == val.description))
            printf("description \n");
        if (!(descriptionFlags == val.descriptionFlags))
            printf("descriptionFlags \n");
        if (!(auraDescription == val.auraDescription))
            printf("auraDescription \n");
        if (!(auraDescriptionFlags == val.auraDescriptionFlags))
            printf("auraDescriptionFlags \n");
        if (!(manaCostPercentage == val.manaCostPercentage))
            printf("manaCostPercentage \n");
        if (!(startRecoveryCategory == val.startRecoveryCategory))
            printf("startRecoveryCategory \n");
        if (!(startRecoveryTime == val.startRecoveryTime))
            printf("startRecoveryTime \n");
        if (!(minTargetLevel == val.minTargetLevel))
            printf("minTargetLevel \n");
        if (!(maxTargetLevel == val.maxTargetLevel))
            printf("maxTargetLevel \n");
        if (!(spellFamilyName == val.spellFamilyName))
            printf("spellFamilyName \n");
        if (!(spellFamilyFlags == val.spellFamilyFlags))
            printf("spellFamilyFlags \n");
        if (!(maxAffectedTargets == val.maxAffectedTargets))
            printf("maxAffectedTargets \n");
        if (!(dmgClass == val.dmgClass))
            printf("dmgClass \n");
        if (!(preventionType == val.preventionType))
            printf("preventionType \n");
        if (!(stanceBarOrder == val.stanceBarOrder))
            printf("stanceBarOrder \n");
        if (!(dmgMultiplier == val.dmgMultiplier))
            printf("dmgMultiplier \n");
        if (!(minFactionId == val.minFactionId))
            printf("minFactionId \n");
        if (!(minReputation == val.minReputation))
            printf("minReputation \n");
        if (!(requiredAuraVision == val.requiredAuraVision))
            printf("requiredAuraVision \n");
        if (!(customFlags == val.customFlags))
            printf("customFlags \n");
    }

    bool operator==(const SpellEntry& val) const
    {
        return (entry == val.entry) &&
            (school == val.school) &&
            (category == val.category) &&
            (castUI == val.castUI) &&
            (dispel == val.dispel) &&
            (mechanic == val.mechanic) &&
            (attributes == val.attributes) &&
            (attributesEx == val.attributesEx) &&
            (attributesEx2 == val.attributesEx2) &&
            (attributesEx3 == val.attributesEx3) &&
            (attributesEx4 == val.attributesEx4) &&
            (stances == val.stances) &&
            (stancesNot == val.stancesNot) &&
            (targets == val.targets) &&
            (targetCreatureType == val.targetCreatureType) &&
            (requiresSpellFocus == val.requiresSpellFocus) &&
            (casterAuraState == val.casterAuraState) &&
            (targetAuraState == val.targetAuraState) &&
            (castingTimeIndex == val.castingTimeIndex) &&
            (recoveryTime == val.recoveryTime) &&
            (categoryRecoveryTime == val.categoryRecoveryTime) &&
            (interruptFlags == val.interruptFlags) &&
            (auraInterruptFlags == val.auraInterruptFlags) &&
            (channelInterruptFlags == val.channelInterruptFlags) &&
            (procFlags == val.procFlags) &&
            (procChance == val.procChance) &&
            (procCharges == val.procCharges) &&
            (maxLevel == val.maxLevel) &&
            (baseLevel == val.baseLevel) &&
            (spellLevel == val.spellLevel) &&
            (durationIndex == val.durationIndex) &&
            (powerType == val.powerType) &&
            (manaCost == val.manaCost) &&
            (manaCostPerlevel == val.manaCostPerlevel) &&
            (manaPerSecond == val.manaPerSecond) &&
            (manaPerSecondPerLevel == val.manaPerSecondPerLevel) &&
            (rangeIndex == val.rangeIndex) &&
            (speed == val.speed) &&
            (modalNextSpell == val.modalNextSpell) &&
            (stackAmount == val.stackAmount) &&
            (totem == val.totem) &&
            (reagent == val.reagent) &&
            (reagentCount == val.reagentCount) &&
            (equippedItemClass == val.equippedItemClass) &&
            (equippedItemSubClassMask == val.equippedItemSubClassMask) &&
            (equippedItemInventoryTypeMask == val.equippedItemInventoryTypeMask) &&
            (effect == val.effect) &&
            (effectDieSides == val.effectDieSides) &&
            (effectBaseDice == val.effectBaseDice) &&
            (effectDicePerLevel == val.effectDicePerLevel) &&
            (effectRealPointsPerLevel == val.effectRealPointsPerLevel) &&
            (effectBasePoints == val.effectBasePoints) &&
            (effectMechanic == val.effectMechanic) &&
            (effectImplicitTargetA == val.effectImplicitTargetA) &&
            (effectImplicitTargetB == val.effectImplicitTargetB) &&
            (effectRadiusIndex == val.effectRadiusIndex) &&
            (effectApplyAuraName == val.effectApplyAuraName) &&
            (effectAmplitude == val.effectAmplitude) &&
            (effectMultipleValue == val.effectMultipleValue) &&
            (effectChainTarget == val.effectChainTarget) &&
            (effectItemType == val.effectItemType) &&
            (effectMiscValue == val.effectMiscValue) &&
            (effectTriggerSpell == val.effectTriggerSpell) &&
            (effectPointsPerComboPoint == val.effectPointsPerComboPoint) &&
            (spellVisual == val.spellVisual) &&
            (spellVisual2 == val.spellVisual2) &&
            (spellIconId == val.spellIconId) &&
            (activeIconID == val.activeIconID) &&
            (spellPriority == val.spellPriority) &&
            (name == val.name) &&
            //(nameFlags == val.nameFlags) &&
            (nameSubtext == val.nameSubtext) &&
            //(nameSubtextFlags == val.nameSubtextFlags) &&
            (description == val.description) &&
            //(descriptionFlags == val.descriptionFlags) &&
            (auraDescription == val.auraDescription) &&
            //(auraDescriptionFlags == val.auraDescriptionFlags) &&
            (manaCostPercentage == val.manaCostPercentage) &&
            (startRecoveryCategory == val.startRecoveryCategory) &&
            (startRecoveryTime == val.startRecoveryTime) &&
            (minTargetLevel == val.minTargetLevel) &&
            (maxTargetLevel == val.maxTargetLevel) &&
            (spellFamilyName == val.spellFamilyName) &&
            (spellFamilyFlags == val.spellFamilyFlags) &&
            (maxAffectedTargets == val.maxAffectedTargets) &&
            (dmgClass == val.dmgClass) &&
            (preventionType == val.preventionType) &&
            (stanceBarOrder == val.stanceBarOrder) &&
            (dmgMultiplier == val.dmgMultiplier) &&
            (minFactionId == val.minFactionId) &&
            (minReputation == val.minReputation) &&
            (requiredAuraVision == val.requiredAuraVision) &&
            (customFlags == val.customFlags);
    }
    
    bool operator<(const SpellEntry& val) const
    {
        if (entry == val.entry)
            return build < val.build;

        return entry < val.entry;
    }
};