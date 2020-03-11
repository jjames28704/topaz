-----------------------------------
--
--
--
-----------------------------------

function onEffectGain(target,effect)
    local jp_value = target:getJobPointValue(tpz.jp.PERFECT_COUNTER)
    target:addMod(tpz.mod.VIT, jp_value)
end

function onEffectTick(target,effect)
end

function onEffectLose(target,effect)
    local jp_value = target:getJobPointValue(tpz.jp.FOOTWORK_EFFECT)
    target:delMod(tpz.mod.VIT, jp_value)
end