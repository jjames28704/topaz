-----------------------------------
--
-- tpz.effect.DEFENDER
--
-----------------------------------
require("scripts/globals/status")
-----------------------------------

function onEffectGain(target,effect)
    local jp_value = target:getJobPointValue(tpz.jp.DEFENDER_EFFECT)
    target:addMod(tpz.mod.DEF, jp_value * 3)
    target:addMod(tpz.mod.DEFP,25)
    target:addMod(tpz.mod.RATTP,-25)
    target:addMod(tpz.mod.ATTP,-25)
end

function onEffectTick(target,effect)
end

function onEffectLose(target,effect)
    local jp_value = target:getJobPointValue(tpz.jp.DEFENDER_EFFECT)
    target:delMod(tpz.mod.DEF, jp_value * 3)
    target:delMod(tpz.mod.DEFP,25)
    target:delMod(tpz.mod.ATTP,-25)
    target:delMod(tpz.mod.RATTP,-25)
end
