-----------------------------------
--
--    tpz.effect.VELOCITY_SHOT
--
-----------------------------------
require("scripts/globals/status")
function onEffectGain(target, effect)
    local jp_value = target:getJobPointValue(tpz.jp.VELOCITY_SHOT_EFFECT)
    target:addMod(tpz.mod.RATT, jp_value * 2)
    target:addMod(tpz.mod.ATTP, -15)
    target:addMod(tpz.mod.HASTE_ABILITY, -1500)
    target:addMod(tpz.mod.RATTP, 15)
    target:addMod(tpz.mod.RANGED_DELAYP, -10)
end

function onEffectTick(target, effect)
end

function onEffectLose(target, effect)
    local jp_value = target:getJobPointValue(tpz.jp.VELOCITY_SHOT_EFFECT)
    target:delMod(tpz.mod.RATT, jp_value * 2)
    target:delMod(tpz.mod.ATTP, -15)
    target:delMod(tpz.mod.HASTE_ABILITY, -1500)
    target:delMod(tpz.mod.RATTP, 15)
    target:delMod(tpz.mod.RANGED_DELAYP, -10)
end
