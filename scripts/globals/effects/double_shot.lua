-----------------------------------
--
--
--
-----------------------------------

function onEffectGain(target,effect)
    local jp_value = target:getJobPointValue(tpz.jp.DOUBLE_SHOT_EFFECT)
    target:addMod(tpz.mod.DOUBLE_SHOT_RATE, effect:getPower() + jp_value)
end

function onEffectTick(target,effect)
end

function onEffectLose(target,effect)
    local jp_value = target:getJobPointValue(tpz.jp.DOUBLE_SHOT_EFFECT)
    target:delMod(tpz.mod.DOUBLE_SHOT_RATE, effect:getPower() + jp_value)
end