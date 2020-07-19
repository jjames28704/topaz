-----------------------------------
--
--
--
-----------------------------------

function onEffectGain(target,effect)
    local jp_value = target:getJobPointValue(tpz.jp.MIKAGE_EFFECT)
    target:addMod(tpz.mod.ATT, 3 * jp_value)
end

function onEffectTick(target,effect)
end

function onEffectLose(target,effect)
    local jp_value = target:getJobPointValue(tpz.jp.MIKAGE_EFFECT)
    target:delMod(tpz.mod.ATT, 3 * jp_value)
end