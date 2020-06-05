-----------------------------------
--
-- tpz.effect.BERSERK
--
-----------------------------------
require("scripts/globals/status")
-----------------------------------

function onEffectGain(target,effect)
    local power = effect:getPower()
    local jp_value = target:getJobPointValue(tpz.jp.BERSERK_EFFECT)
    local jp_effect = jp_value * 2

    target:addMod(tpz.mod.ATTP, power)
    target:addMod(tpz.mod.RATTP, power)
    target:addMod(tpz.mod.DEFP, -power)
    target:addMod(tpz.mod.ATT, jp_effect)
    target:addMod(tpz.mod.RATT, jp_effect)
end

function onEffectTick(target,effect)
end

function onEffectLose(target,effect)
    local power = effect:getPower()
    local jp_value = target:getJobPointValue(tpz.jp.BERSERK_EFFECT)
    local jp_effect = jp_value * 2

    target:delMod(tpz.mod.ATTP, power)
    target:delMod(tpz.mod.RATTP, power)
    target:delMod(tpz.mod.DEFP, -power)
    target:delMod(tpz.mod.ATT, jp_effect)
    target:delMod(tpz.mod.RATT, jp_effect)
end
