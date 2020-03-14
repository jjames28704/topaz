-----------------------------------
-- Ability: Activate
-- Calls forth your automaton.
-- Obtained: Puppetmaster Level 1
-- Recast Time: 0:20:00 (0:16:40 with full merits)
-- Duration: Instant
-----------------------------------
require("scripts/globals/settings")
require("scripts/globals/status")
require("scripts/globals/pets")
require("scripts/globals/msg")
-----------------------------------

function onAbilityCheck(player, target, ability)
    if player:getPet() ~= nil then
        return tpz.msg.basic.ALREADY_HAS_A_PET,0
    elseif not player:canUseMisc(tpz.zoneMisc.PET) then
        return tpz.msg.basic.CANT_BE_USED_IN_AREA,0
    else
        return 0,0
    end
end

function onUseAbility(player,target,ability)
    player:spawnPet(tpz.pet.id.AUTOMATON)
    local pet = player:getPet()
    if pet then
        local jp_value = player:getJobPointValue(tpz.jp.ACTIVATE_EFFECT)
        pet:addMod(tpz.mod.HP, jp_value * 10)
        pet:addMod(tpz.mod.MP, jp_value * 11)
    end
end