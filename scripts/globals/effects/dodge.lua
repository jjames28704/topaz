-----------------------------------
--
--     tpz.effect.DODGE
--
-----------------------------------
require("scripts/globals/status")
-----------------------------------

function onEffectGain(target,effect)
    local jp_value = target:getJobPointValue(tpz.jp.DODGE_EFFECT) * 2
    target:addMod(tpz.mod.EVA,effect:getPower() + jp_value)
end

function onEffectTick(target,effect)
end

function onEffectLose(target,effect)
    local jp_value = target:getJobPointValue(tpz.jp.HUNDRED_FISTS_EFFECT) * 2
    target:delMod(tpz.mod.EVA,effect:getPower() + jp_value)
end