-----------------------------------
--
--    tpz.effect.SHARPSHOT
--
-----------------------------------
require("scripts/globals/status")
-----------------------------------

function onEffectGain(target,effect)
    local jp_value = target:getJobPointValue(tpz.jp.SEIGAN_EFFECT)
    target:addMod(tpz.mod.RACC,effect:getPower())
    target:addMod(tpz.mod.RATT,jp_value * 2)
end

function onEffectTick(target,effect)
end

function onEffectLose(target,effect)
    local jp_value = target:getJobPointValue(tpz.jp.SEIGAN_EFFECT)
    target:delMod(tpz.mod.RACC,effect:getPower())
    target:delMod(tpz.mod.RATT,jp_value * 2)
end