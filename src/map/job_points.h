/*
===========================================================================

  Copyright (c) 2010-2015 Darkstar Dev Teams

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see http://www.gnu.org/licenses/

  This file is part of DarkStar-server source code.

===========================================================================
*/

#ifndef _CJOBPOINTS_H
#define _CJOBPOINTS_H

#include "../common/cbasetypes.h"

/************************************************************************
*                                                                       *
* Offsets for each job point category (main job)                        *
*                                                                       *
************************************************************************/
enum JOBPOINT_CATEGORIES
{
    JPCATEGORY_WAR      = 0x040,
    JPCATEGORY_MNK      = 0x080,
    JPCATEGORY_WHM      = 0x0C0,
    JPCATEGORY_BLM      = 0x100,
    JPCATEGORY_RDM      = 0x140,
    JPCATEGORY_THF      = 0x180,
    JPCATEGORY_PLD      = 0x1C0,
    JPCATEGORY_DRK      = 0x200,
    JPCATEGORY_BST      = 0x240,
    JPCATEGORY_BRD      = 0x280,
    JPCATEGORY_RNG      = 0x2C0,
    JPCATEGORY_SAM      = 0x300,
    JPCATEGORY_NIN      = 0x340,
    JPCATEGORY_DRG      = 0x380,
    JPCATEGORY_SMN      = 0x3C0,
    JPCATEGORY_BLU      = 0x400,
    JPCATEGORY_COR      = 0x440,
    JPCATEGORY_PUP      = 0x480,
    JPCATEGORY_DNC      = 0x4C0,
    JPCATEGORY_SCH      = 0x500,
    JPCATEGORY_GEO      = 0x540,
    JPCATEGORY_RUN      = 0x580,
};

/************************************************************************
*                                                                       *
* Bonuses for each job point                                            *
*                                                                       *
************************************************************************/
enum JOBPOINT_TYPES
{
    //WAR
    JP_MIGHTY_STRIKES_EFFECT    = JPCATEGORY_WAR + 0x00, //p.acc +2
    JP_BRAZEN_RUSH_EFFECT       = JPCATEGORY_WAR + 0x02, //p.atk +4
    JP_BERSERK_EFFECT           = JPCATEGORY_WAR + 0x04, //p.atk +2
    JP_DEFENDER_EFFECT          = JPCATEGORY_WAR + 0x06, //p.def +3
    JP_WARCRY_EFFECT            = JPCATEGORY_WAR + 0x08, //p.atk +3
    JP_AGGRESSOR_EFFECT         = JPCATEGORY_WAR + 0x0A, //p.acc +1
    JP_RETALIATION_EFFECT       = JPCATEGORY_WAR + 0x0C, //retaliation chance +1
    JP_RESTRAINT_EFFECT         = JPCATEGORY_WAR + 0x0E, //time to max ws bonus -2%
    JP_BLOOD_RAGE_EFFECT        = JPCATEGORY_WAR + 0x10, //crit. hit rate +1
    JP_DOUBLE_ATTACK_EFFECT     = JPCATEGORY_WAR + 0x12, //double attack p.atk +1

    //MNK
    JP_HUNDRED_FIRTS_EFFECT     = JPCATEGORY_MNK + 0x00, //p.acc +2
    JP_INNER_STRENGTH_EFFECT    = JPCATEGORY_MNK + 0x02, //hp recovered +2%
    JP_DODGE_EFFECT             = JPCATEGORY_MNK + 0x04, //evasion +2
    JP_FOCUS_EFFECT             = JPCATEGORY_MNK + 0x06, //accuracy +1
    JP_CHAKRA_EFFECT            = JPCATEGORY_MNK + 0x08, //hp recovered from use +10
    JP_COUNTERSTANCE_EFFECT     = JPCATEGORY_MNK + 0x0A, //DEX +2
    JP_FOOTWORK_EFFECT          = JPCATEGORY_MNK + 0x0C, //kick attack dmg +1
    JP_PERFECT_COUNTER_EFFECT   = JPCATEGORY_MNK + 0x0E, //VIT bonus +1
    JP_IMPETUS_EFFECT           = JPCATEGORY_MNK + 0x10, //maximum p.atk +2
    JP_KICK_ATTACKS_EFFECT      = JPCATEGORY_MNK + 0x12, //kick attacks atk +2 acc +1

    //WHM
    JP_BENEDICTION_EFFECT       = JPCATEGORY_WHM + 0x00, //mp recovered +1%
    JP_ASYLUM_EFFECT            = JPCATEGORY_WHM + 0x02, //m.eva +4
    JP_DIVINE_SEAL_EFFECT       = JPCATEGORY_WHM + 0x04, //reduce emnity from use +3
    JP_WHM_MAGIC_ACC_BONUS      = JPCATEGORY_WHM + 0x06, //m.acc +1
    JP_AFFLATUS_SOLACE_EFFECT   = JPCATEGORY_WHM + 0x08, //cure potency +2 (not %)
    JP_AFFLATUS_MISERY_EFFECT   = JPCATEGORY_WHM + 0x0A, //banish +2 m.dmg, miss => acc +1 dmg +1
    JP_DIVINE_CARESS_DURATION   = JPCATEGORY_WHM + 0x0C, //dur. +2 sec
    JP_SACROSANCTITY_EFFECT     = JPCATEGORY_WHM + 0x0E, //minimum DEF +1
    JP_REGEN_DURATION           = JPCATEGORY_WHM + 0x10, //dur. +3 sec
    JP_BAR_SPELL_EFFECT         = JPCATEGORY_WHM + 0x12, //resistance +2

    //BLM
    JP_MANAFONT_EFFECT          = JPCATEGORY_BLM + 0x00, //elemental m.dmg +2
    JP_SUBTLE_SORCERY_EFFECT    = JPCATEGORY_BLM + 0x02, //spellcasting time -1%
    JP_ELEMENTAL_SEAL_EFFECT    = JPCATEGORY_BLM + 0x04, //elemental magic emnity -3
    JP_MAGIC_BURST_DMG_BONUS    = JPCATEGORY_BLM + 0x06, //magic burst dmg +1%
    JP_MANA_WALL_EFFECT         = JPCATEGORY_BLM + 0x08, //mp consumed -1%
    JP_BLM_MAGIC_ACC_BONUS      = JPCATEGORY_BLM + 0x0A, //m.acc +1
    JP_EMNITY_DOUSE_RECAST      = JPCATEGORY_BLM + 0x0C, //recast -3sec
    JP_MANAWELL_EFFECT          = JPCATEGORY_BLM + 0x0E, //m.dmg +1
    JP_MAGIC_BURST_EMNITY_BONUS = JPCATEGORY_BLM + 0x10, //emnity -1
    JP_MAGIC_DMG_BONUS          = JPCATEGORY_BLM + 0x12, //m.dmg +1

    //RDM
    JP_CHAINSPELL_EFFECT        = JPCATEGORY_RDM + 0x00, //elem. m.dmg +2
    JP_STYMIE_EFFECT            = JPCATEGORY_RDM + 0x02, //effect dur. +1s
    JP_CONVERT_EFFECT           = JPCATEGORY_RDM + 0x04, //HP consumed -1%
    JP_RDM_MAGIC_ACC_BONUS      = JPCATEGORY_RDM + 0x06, //m.acc +1
    JP_COMPOSURE_EFFECT         = JPCATEGORY_RDM + 0x08, //p.acc +1
    JP_RDM_MAGIC_ATK_BONUS      = JPCATEGORY_RDM + 0x0A, //MAB +1
    JP_SABOTEUR_EFFECT          = JPCATEGORY_RDM + 0x0C, //enfeeble m.acc +2
    JP_ENFEEBLE_DURATION        = JPCATEGORY_RDM + 0x0E, //enfeeble dur. +1s
    JP_QUICK_MAGIC_EFFECT       = JPCATEGORY_RDM + 0x10, //MP consumption -2%
    JP_ENHANCING_DURATION       = JPCATEGORY_RDM + 0x12, //dur. +1s

    //THF
    JP_PERFECT_DODGE_EFFECT     = JPCATEGORY_THF + 0x00, //m.eva +3
    JP_LARCENY_EFFECT           = JPCATEGORY_THF + 0x02, //dur. +1s
    JP_SNEAK_ATTACK_EFFECT      = JPCATEGORY_THF + 0x04, //DEX bonus +1%
    JP_TRICK_ATTACK_EFFECT      = JPCATEGORY_THF + 0x06, //AGI bonus +1%
    JP_STEAL_RECAST             = JPCATEGORY_THF + 0x08, //recast -2s
    JP_MUG_EFFECT               = JPCATEGORY_THF + 0x0A, //drain HP == 5% (DEX + AGI)
    JP_DESPOIL_EFFECT           = JPCATEGORY_THF + 0x0C, //drain 2% tp
    JP_CONSPIRATOR_EFFECT       = JPCATEGORY_THF + 0x0E, //p.acc +1
    JP_BULLY_EFFECT             = JPCATEGORY_THF + 0x10, //intimidation chance +1%
    JP_TRIPLE_ATTACK_EFFECT     = JPCATEGORY_THF + 0x12, //p.atk +1

    //PLD
    JP_INVINCIBLE_EFFECT        = JPCATEGORY_PLD + 0x00, //emnity +100
    JP_INTERVENE_EFFECT         = JPCATEGORY_PLD + 0x02, //dmg +2%
    JP_HOLY_CIRCLE_EFFECT       = JPCATEGORY_PLD + 0x04, //dmg taken -1
    JP_SENTINEL_EFFECT          = JPCATEGORY_PLD + 0x06, //emnity +1
    JP_SHIELD_BASH_EFFECT       = JPCATEGORY_PLD + 0x08, //dmg +10
    JP_COVER_DURATION           = JPCATEGORY_PLD + 0x0A, //dur. +1s
    JP_DIVINE_EMBLEM_EFFECT     = JPCATEGORY_PLD + 0x0C, //m.dmg +2
    JP_SEPULCHER_DURATION       = JPCATEGORY_PLD + 0x0E, //dur. +1s
    JP_PALISADE_EFFECT          = JPCATEGORY_PLD + 0x10, //block chance +1%
    JP_ENLIGHT_EFFECT           = JPCATEGORY_PLD + 0x12, //ae.dmg +1 p.acc +1

    //DRK
    JP_BLOOD_WEAPON_EFFECT      = JPCATEGORY_DRK + 0x00, //hp absorb +2%
    JP_SOUL_ENSLAVEMENT_EFFECT  = JPCATEGORY_DRK + 0x02, //tp absorb +1%
    JP_ARCANE_CIRCLE_EFFECT     = JPCATEGORY_DRK + 0x04, //dmg taken -1
    JP_LAST_RESORT_EFFECT       = JPCATEGORY_DRK + 0x06, //p.atk +2
    JP_SOULEATER_DURATION       = JPCATEGORY_DRK + 0x08, //dur. +1s
    JP_WEAPON_BASH_EFFECT       = JPCATEGORY_DRK + 0x0A, //dmg +10
    JP_NETHER_VOID_EFFECT       = JPCATEGORY_DRK + 0x0C, //absorb +2% abs-attri status +1/10
    JP_ARCANE_CREST_DURATION    = JPCATEGORY_DRK + 0x0E, //dur. +1s
    JP_SCARLET_DLRIUM_DURATION  = JPCATEGORY_DRK + 0x10, //dur. +1s
    JP_ENDARK_EFFECT            = JPCATEGORY_DRK + 0x12, //p.dmg p.atk p.acc +1

    //BST
    JP_FAMILIAR_EFFECT          = JPCATEGORY_BST + 0x00, //all pet attr. +3
    JP_UNLEASH_EFFECT           = JPCATEGORY_BST + 0x02, //sp.atk dmg +2%
    JP_PET_ACC_BONUS            = JPCATEGORY_BST + 0x04, //pet p.acc +1
    JP_CHARM_SUCCESS_RATE       = JPCATEGORY_BST + 0x06, //success rate +1%
    JP_REWARD_EFFECT            = JPCATEGORY_BST + 0x08, //pet hp recov. +1%
    JP_PET_ATK_SPD_BONUS        = JPCATEGORY_BST + 0x0A, //pet atk spd +1%
    JP_READY_EFFECT             = JPCATEGORY_BST + 0x0C, //pet sp.ability dmg +1%
    JP_SPUR_EFFECT              = JPCATEGORY_BST + 0x0E, //pet p.atk +3
    JP_RUN_WILD_DURATION        = JPCATEGORY_BST + 0x10, //dur. +2s
    JP_PET_EMNITY_BONUS         = JPCATEGORY_BST + 0x12, //emnity +1

    //BRD
    JP_SOUL_VOICE_EFFECT        = JPCATEGORY_BRD + 0x00, //casting time -2%
    JP_CLARION_CALL_EFFECT      = JPCATEGORY_BRD + 0x02, //effect dur. +2s
    JP_MINNE_EFFECT             = JPCATEGORY_BRD + 0x04, //p.def +1
    JP_MINUET_EFFECT            = JPCATEGORY_BRD + 0x06, //p.atk +1
    JP_PIANISSIMO_EFFECT        = JPCATEGORY_BRD + 0x08, //casting time -2%
    JP_SONG_ACC_BONUS           = JPCATEGORY_BRD + 0x0A, //song acc +1
    JP_TENUTO_EFFECT            = JPCATEGORY_BRD + 0x0C, //song dur. +1s
    JP_LULLABY_DURATION         = JPCATEGORY_BRD + 0x0E, //lullaby dur. +1
    JP_MARCATO_EFFECT           = JPCATEGORY_BRD + 0x10, //song dur. +1s
    JP_REQUIEM_EFFECT           = JPCATEGORY_BRD + 0x12, //dot dmg +3

    //RNG
    JP_EAGLE_EYE_SHOT_EFFECT    = JPCATEGORY_RNG + 0x00, //dmg +3%
    JP_OVERKILL_EFFECT          = JPCATEGORY_RNG + 0x02, //emnity -1
    JP_SHARPSHOT_EFFECT         = JPCATEGORY_RNG + 0x04, //r.atk +2
    JP_CAMOUFLAGE_EFFECT        = JPCATEGORY_RNG + 0x06, //crit. hit rate +1%
    JP_BARRAGE_EFFECT           = JPCATEGORY_RNG + 0x08, //r.atk +3
    JP_SHADOWBIND_DURATION      = JPCATEGORY_RNG + 0x0A, //dur. +1s
    JP_VELOCITY_SHOT_EFFECT     = JPCATEGORY_RNG + 0x0C, //r.atk +2
    JP_DOUBLE_SHOT_EFFECT       = JPCATEGORY_RNG + 0x0E, //chance +1%
    JP_DECOY_SHOT_EFFECT        = JPCATEGORY_RNG + 0x10, //max emnity vol. +15, cum. +5
    JP_UNLIMITED_SHOT_EFFECT    = JPCATEGORY_RNG + 0x12, //emnity -2

    //SAM
    JP_MEIKYO_SHISUI_EFFECT     = JPCATEGORY_SAM + 0x00, //sc dmg +2%
    JP_YAEGASUMI_EFFECT         = JPCATEGORY_SAM + 0x02, //tp bonus +30
    JP_WARDING_CIRCLE_EFFECT    = JPCATEGORY_SAM + 0x04, //dmg taken -1
    JP_HASSO_EFFECT             = JPCATEGORY_SAM + 0x06, //STR +1
    JP_MEDITATE_EFFECT          = JPCATEGORY_SAM + 0x08, //tp +5 per tick
    JP_SEIGAN_EFFECT            = JPCATEGORY_SAM + 0x0A, //p.def +3
    JP_KONZEN_ITTAI_EFFECT      = JPCATEGORY_SAM + 0x0C, //sc dmg +1%
    JP_HAMANOHA_DURATION        = JPCATEGORY_SAM + 0x0E, //dur. +1s
    JP_HAGAKURE_EFFECT          = JPCATEGORY_SAM + 0x10, //tp bonus +10
    JP_ZANSHIN_EFFECT           = JPCATEGORY_SAM + 0x12, //zanshin follow-ups p.atk +2

    //NIN
    JP_MIJIN_GAUKURE_EFFECT     = JPCATEGORY_NIN + 0x00, //dmg +3%
    JP_MIKAGE_EFFECT            = JPCATEGORY_NIN + 0x02, //p.atk +3
    JP_YONIN_EFFECT             = JPCATEGORY_NIN + 0x04, //p.eva +2
    JP_ININ_EFFECT              = JPCATEGORY_NIN + 0x06, //p.acc +1
    JP_NINJITSU_ACC_BONUS       = JPCATEGORY_NIN + 0x08, //ninjitsu acc +1
    JP_NINJITSU_CAST_TIME_BONUS = JPCATEGORY_NIN + 0x0A, //casting time -1%
    JP_FUTAE_EFFECT             = JPCATEGORY_NIN + 0x0C, //m.dmg +5
    JP_ELEM_NINJITSU_EFFECT     = JPCATEGORY_NIN + 0x0E, //m.dmg +2
    JP_ISSEKIGAN_EFFECT         = JPCATEGORY_NIN + 0x10, //vol. emnity +10
    JP_TACTICAL_PARRY_EFFECT    = JPCATEGORY_NIN + 0x12, //counter when parry +1%

    //DRG
    JP_SPIRIT_SURGE_EFFECT      = JPCATEGORY_DRG + 0x00, //Weapon DMG +1
    JP_FLY_HIGH_EFFECT          = JPCATEGORY_DRG + 0x02, //all jump p.atk +5
    JP_ANCIENT_CIRCLE_EFFECT    = JPCATEGORY_DRG + 0x04, //dmg taken -1
    JP_JUMP_EFFECT              = JPCATEGORY_DRG + 0x06, //jump/spirit jump p.atk +3
    JP_SPIRIT_LINK_EFFECT       = JPCATEGORY_DRG + 0x08, //hp consumption -1%
    JP_WYVERN_MAX_HP_BONUS      = JPCATEGORY_DRG + 0x0A, //wyvern max hp +10
    JP_DRAGON_BREAKER_DURATION  = JPCATEGORY_DRG + 0x0C, //dur. +1s
    JP_WYVERN_BREATH_EFFECT     = JPCATEGORY_DRG + 0x0E, //breath effect +10
    JP_HIGH_JUMP_EFFECT         = JPCATEGORY_DRG + 0x10, //high jump/soul jump atk +3
    JP_WYVERN_ATTR_BONUS        = JPCATEGORY_DRG + 0x12, //wyvern p.atk/p.def +2

    //SMN
    JP_ASTRAL_FLOW_EFFECT       = JPCATEGORY_SMN + 0x00, //all pet attr. +5
    JP_ASTRAL_CONDUIT_EFFECT    = JPCATEGORY_SMN + 0x02, //BPR: dmg +1% BPW: duration +1%
    JP_SUMMON_ACC_BONUS         = JPCATEGORY_SMN + 0x04, //pet p.acc +1
    JP_SUMMON_MAGIC_ACC_BONUS   = JPCATEGORY_SMN + 0x06, //pet m.acc +1
    JP_ELEMENTAL_SIPHON_EFFECT  = JPCATEGORY_SMN + 0x08, //mp recov. +3
    JP_SUMMON_PHYS_ATK_BONUS    = JPCATEGORY_SMN + 0x0A, //pet p.atk +2
    JP_MANA_CEDE_EFFECT         = JPCATEGORY_SMN + 0x0C, //pet tp +50
    JP_AVATARS_FAVOR_EFFECT     = JPCATEGORY_SMN + 0x0E, //favor +3s dur. bonus
    JP_SUMMON_MAGIC_DMG_BONUS   = JPCATEGORY_SMN + 0x10, //pet m.dmg +5
    JP_BLOOD_PACT_DMG_BONUS     = JPCATEGORY_SMN + 0x12, //BPR/BPW dmg +5

    //BLU
    JP_AZURE_LORE_EFFECT        = JPCATEGORY_BLU + 0x00, //dmg +1
    JP_UNBRIDLED_WISDOM_EFFECT  = JPCATEGORY_BLU + 0x02, //conserve mp +3
    JP_BLUE_MAGIC_POINT_BONUS   = JPCATEGORY_BLU + 0x04, //blue magic points +1
    JP_BURST_AFFINITY_BONUS     = JPCATEGORY_BLU + 0x06, //dmg +2
    JP_CHAIN_AFFINITY_EFFECT    = JPCATEGORY_BLU + 0x08, //sc dmg +1%
    JP_BLUE_PHYS_AE_ACC_BONUS   = JPCATEGORY_BLU + 0x0A, //phys. add. effect acc +1
    JP_UNBRIDLED_LRN_EFFECT     = JPCATEGORY_BLU + 0x0C, //dmg +1%
    JP_UNBRIDLED_LRN_EFFECT_II  = JPCATEGORY_BLU + 0x0E, //party enhancing dur. +1%
    JP_EFFLUX_EFFECT            = JPCATEGORY_BLU + 0x10, //tp bonus +10
    JP_BLU_MAGIC_ACC_BONUS      = JPCATEGORY_BLU + 0x12, //m.acc +1

    //COR
    JP_WILD_CARD_EFFECT         = JPCATEGORY_COR + 0x00, //probability of reset +1%
    JP_CUTTING_CARDS_EFFECT     = JPCATEGORY_COR + 0x02, //recast of party abil. -1%
    JP_PHANTOM_ROLL_DURATION    = JPCATEGORY_COR + 0x04, //dur. +2s
    JP_BUST_EVASION             = JPCATEGORY_COR + 0x06, //bust chance -1%
    JP_QUICK_DRAW_EFFECT        = JPCATEGORY_COR + 0x08, //m.dmg +2
    JP_AMMO_CONSUMPTION         = JPCATEGORY_COR + 0x0A, //no ammo chance +1%
    JP_RANDOM_DEAL_EFFECT       = JPCATEGORY_COR + 0x0C, //2 abil random deal +2%
    JP_COR_RANGED_ACC_BONUS     = JPCATEGORY_COR + 0x0E, //r.acc +1
    JP_TRIPLE_SHOT_EFFECT       = JPCATEGORY_COR + 0x10, //triple shot chance +1%
    JP_OPTIMAL_RANGE_BONUS      = JPCATEGORY_COR + 0x12, //sweet spot dmg +1

    //PUP
    JP_OVERDRIVE_EFFECT         = JPCATEGORY_PUP + 0x00, //all pet attr. +5
    JP_HEADY_ARTIFICE_EFFECT    = JPCATEGORY_PUP + 0x02, //increase head effects (see wiki)
    JP_AUTOMATON_HP_MP_BONUS    = JPCATEGORY_PUP + 0x04, //pet hp+10, mp+5
    JP_ACTIVATE_EFFECT          = JPCATEGORY_PUP + 0x06, //burden -1
    JP_REPAIR_EFFECT            = JPCATEGORY_PUP + 0x08, //mp hot based on oil (see wiki)
    JP_DEUS_EX_AUTOMATA_RECAST  = JPCATEGORY_PUP + 0x0A, //recast -1s
    JP_TACTICAL_SWITCH_BONUS    = JPCATEGORY_PUP + 0x0C, //tp +20
    JP_COOLDOWN_EFFECT          = JPCATEGORY_PUP + 0x0E, //burden -1
    JP_DEACTIVATE_EFFECT        = JPCATEGORY_PUP + 0x10, //hp require. -1%
    JP_PUP_MARTIAL_ARTS_EFFECT  = JPCATEGORY_PUP + 0x12, //delay -2

    //DNC
    JP_TRANCE_EFFECT            = JPCATEGORY_DNC + 0x00, //tp +100
    JP_GRAND_PAS_EFFECT         = JPCATEGORY_DNC + 0x02, //dmg +1
    JP_STEP_DURATION            = JPCATEGORY_DNC + 0x04, //dur. +1s
    JP_WALTZ_POTENCY_BONUS      = JPCATEGORY_DNC + 0x06, //dur. +2s
    JP_WALTZ_POTENCY_BONUS      = JPCATEGORY_DNC + 0x08, //waltz potency +2 (not %)
    JP_JIG_DURATION             = JPCATEGORY_DNC + 0x0A, //dur. +1s
    JP_FLOURISH_I_EFFECT        = JPCATEGORY_DNC + 0x0C, //effect bonuses (see wiki)
    JP_FLOURISH_II_EFFECT       = JPCATEGORY_DNC + 0x0E, //effect bonuses (see wiki)
    JP_FLOURISH_III_EFFECT      = JPCATEGORY_DNC + 0x10, //CHR bonus +1%
    JP_CONTRADANCE_EFFECT       = JPCATEGORY_DNC + 0x12, //waltz tp -3%

    //SCH
    JP_TABULA_RASA_EFFECT       = JPCATEGORY_SCH + 0x00, //mp recov. +2%
    JP_CAPER_EMMISSARIUS_EFFECT = JPCATEGORY_SCH + 0x02, //hp recov. +2%
    JP_LIGHT_ARTS_EFFECT        = JPCATEGORY_SCH + 0x04, //dur. +3s
    JP_DARK_ARTS_EFFECT         = JPCATEGORY_SCH + 0x06, //dur. +3s
    JP_STRATEGEM_EFFECT_I       = JPCATEGORY_SCH + 0x08, //m.acc +1
    JP_STRATEGEM_EFFECT_II      = JPCATEGORY_SCH + 0x0A, //cast time -1%
    JP_STRATEGEM_EFFECT_III     = JPCATEGORY_SCH + 0x0C, //m.dmg +2
    JP_STRATEGEM_EFFECT_IV      = JPCATEGORY_SCH + 0x0E, //recast -2%
    JP_MODUS_VERITAS_EFFECT     = JPCATEGORY_SCH + 0x10, //dot +3
    JP_SUBLIMATION_EFFECT       = JPCATEGORY_SCH + 0x12, //sublimation mp +3%

    //GEO
    JP_BOLSTER_EFFECT           = JPCATEGORY_GEO + 0x00, //luopan hp +3% perp. -1mp
    JP_WIDENED_COMPASS_EFFECT   = JPCATEGORY_GEO + 0x02, //cast time -3%
    JP_LIFE_CYCLE_EFFECT        = JPCATEGORY_GEO + 0x04, //luopan hp recov. +1%
    JP_BLAZE_OF_GLORY_EFFECT    = JPCATEGORY_GEO + 0x06, //luopan init. hp +1%
    JP_GEO_MAGIC_ATK_BONUS      = JPCATEGORY_GEO + 0x08, //m.att bonus +1
    JP_GEO_MAGIC_ACC_BONUS      = JPCATEGORY_GEO + 0x0A, //m.acc +1
    JP_DEMATERIALIZE_DURATION   = JPCATEGORY_GEO + 0x0C, //dur. +1s
    JP_THEURGIC_FOCUS_EFFECT    = JPCATEGORY_GEO + 0x0E, //m.dmg +3
    JP_CONCENTRIC_PULSE_EFFECT  = JPCATEGORY_GEO + 0x10, //dmg +1%
    JP_INDI_SPELL_DURATION      = JPCATEGORY_GEO + 0x12, //indi dur. +2s

    //RUN
    JP_ELEMENTAL_SFORZO_EFFECT  = JPCATEGORY_RUN + 0x00, //dmg absorb +2%
    JP_ODYLLIC_SUBTER_EFFECT    = JPCATEGORY_RUN + 0x02, //enemy m.att bonus -2
    JP_RUNE_ENCHANTMENT_EFFECT  = JPCATEGORY_RUN + 0x04, //rune resist +1
    JP_VALLATION_DURATION       = JPCATEGORY_RUN + 0x06, //dur. +1s
    JP_SWORDPLAY_EFFECT         = JPCATEGORY_RUN + 0x08, //max p.acc/p.eva +2
    JP_SWIPE_EFFECT             = JPCATEGORY_RUN + 0x0A, //swipe/lunge dmg (skill) +1%
    JP_EMBOLDEN_EFFECT          = JPCATEGORY_RUN + 0x0C, //enhanc. mag effect +1
    JP_VIVACIOUS_PULSE_EFFECT   = JPCATEGORY_RUN + 0x0E, //viv. pulse => hp +1%
    JP_ONE_FOR_ALL_DURATION     = JPCATEGORY_RUN + 0x10, //dur. +1s
    JP_GAMBIT_DURATION          = JPCATEGORY_RUN + 0x12, //dur +1s
};

#endif
