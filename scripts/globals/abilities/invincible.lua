-----------------------------------
-- Ability: Invincible
-- Grants immunity to all physical attacks.
-- Obtained: Paladin Level 1
-- Recast Time: 1:00:00
-- Duration: 0:00:30
-----------------------------------
require("scripts/globals/settings")
require("scripts/globals/status")
-----------------------------------

function onAbilityCheck(player,target,ability)
    return 0,0
end

function onUseAbility(player,target,ability)
    local jp_value = player:getJobPointValue(tpz.jp.INVINCIBLE_EFFECT)
    ability:setVE(ability:getVE() + 100 * jp_value)
    player:addStatusEffect(tpz.effect.INVINCIBLE,1,0,30)
end