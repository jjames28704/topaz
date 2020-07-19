-----------------------------------
--
--     tpz.effect.HUNDRED_FISTS
--
-----------------------------------

function onEffectGain(target,effect)
    local jp_value = target:getJobPointValue(tpz.jp.HUNDRED_FISTS_EFFECT)
    target:addMod(tpz.mod.ACC, jp_value * 2)
end

function onEffectTick(target,effect)
end

function onEffectLose(target,effect)
    local jp_value = target:getJobPointValue(tpz.jp.HUNDRED_FISTS_EFFECT)
    target:delMod(tpz.mod.ACC, jp_value * 2)
end