-----------------------------------
--
--
--
-----------------------------------

function onEffectGain(target,effect)
    local jp_value = target:getJobPointValue(tpz.jp.BARRAGE_EFFECT)
    target:addMod(tpz.mod.RATT, jp_value * 3)
end

function onEffectTick(target,effect)
end

function onEffectLose(target,effect)
    local jp_value = target:getJobPointValue(tpz.jp.BARRAGE_EFFECT)
    target:delMod(tpz.mod.RATT, jp_value * 3)
end