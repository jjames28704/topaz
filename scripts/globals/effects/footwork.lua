-----------------------------------
--
--
--
-----------------------------------
require("scripts/globals/status")
-----------------------------------

function onEffectGain(target, effect)
    local jp_value = target:getJobPointValue(tpz.jp.FOOTWORK_EFFECT)
    target:addMod(tpz.mod.KICK_ATTACK_RATE, 20)
    target:addMod(tpz.mod.KICK_DMG, effect:getPower() + jp_value)
end

function onEffectTick(target, effect)
end

function onEffectLose(target, effect)
    local jp_value = target:getJobPointValue(tpz.jp.FOOTWORK_EFFECT)
    target:delMod(tpz.mod.KICK_ATTACK_RATE, 20)
    target:delMod(tpz.mod.KICK_DMG, effect:getPower() + jp_value)
end