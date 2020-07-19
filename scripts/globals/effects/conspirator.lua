-----------------------------------
--
-- tpz.effect.CONSPIRATOR
--
-----------------------------------
require("scripts/globals/status")

function onEffectGain(target,effect)
    local jp_value = target:getJobPointValue(tpz.jp.CONSPIRATOR_EFFECT)
    target:addMod(tpz.mod.SUBTLE_BLOW, effect:getPower())
    target:addMod(tpz.mod.ACC, effect:getSubPower() + jp_value)
end

function onEffectTick(target,effect)
end

function onEffectLose(target,effect)
    local jp_value = target:getJobPointValue(tpz.jp.CONSPIRATOR_EFFECT)
    target:delMod(tpz.mod.SUBTLE_BLOW, effect:getPower())
    target:delMod(tpz.mod.ACC, effect:getSubPower() + jp_value)
end
