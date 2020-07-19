-----------------------------------
--
--     tpz.effect.PERFECT_DODGE
--
-----------------------------------

function onEffectGain(target,effect)
    local jp_value = target:getJobPointValue(tpz.jp.PERFECT_DODGE_EFFECT)
    target:addMod(tpz.mod.MEVA, jp_value * 3)
end

function onEffectTick(target,effect)
end

function onEffectLose(target,effect)
    local jp_value = target:getJobPointValue(tpz.jp.PERFECT_DODGE_EFFECT)
    target:delMod(tpz.mod.MEVA, jp_value * 3)
end