-----------------------------------
--
--
--
-----------------------------------

function onEffectGain(target,effect)
    local jp_value = target:getJobPointValue(tpz.jp.UNLIMITED_SHOT_EFFECT)
    target:addMod(tpz.mod.ENMITY, -2 * jp_value)
end

function onEffectTick(target,effect)
end

function onEffectLose(target,effect)
    local jp_value = target:getJobPointValue(tpz.jp.UNLIMITED_SHOT_EFFECT)
    target:delMod(tpz.mod.ENMITY, -2 * jp_value)
end