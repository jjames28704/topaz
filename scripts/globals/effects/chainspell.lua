-----------------------------------
--
-- tpz.effect.CHAINSPELL
--
-----------------------------------
require("scripts/globals/status")
-----------------------------------

function onEffectGain(target,effect)
    local jp_value = target:getJobPointValue(tpz.jp.CHAINSPELL_EFFECT)
    target:addMod(tpz.mod.UFASTCAST,150)
    target:addMod(tpz.mod.MAGIC_DAMAGE, jp_value * 2)
end

function onEffectTick(target,effect)
end

function onEffectLose(target,effect)
    local jp_value = target:getJobPointValue(tpz.jp.CHAINSPELL_EFFECT)
    target:delMod(tpz.mod.UFASTCAST,150)
    target:delMod(tpz.mod.MAGIC_DAMAGE, jp_value * 2)
end