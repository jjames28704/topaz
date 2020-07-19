-----------------------------------
--
--     tpz.effect.HAGAKURE
--
-----------------------------------

require("scripts/globals/status")

function onEffectGain(target,effect)
    local jp_value = target:getJobPointValue(tpz.jp.HAGAKURE_EFFECT)
    target:addMod(tpz.mod.SAVETP,400)
    target:addMod(tpz.mod.TP_BONUS,1000 + (jp_value * 10))
end

function onEffectTick(target,effect)
end

function onEffectLose(target,effect)
    local jp_value = target:getJobPointValue(tpz.jp.HAGAKURE_EFFECT)
    target:delMod(tpz.mod.SAVETP,400)
    target:delMod(tpz.mod.TP_BONUS,1000 + (jp_value * 10))
end
