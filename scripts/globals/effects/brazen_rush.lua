-----------------------------------
--
-- tpz.effect.BRAZEN_RUSH
--
-----------------------------------
require("scripts/globals/status")
-----------------------------------

function onEffectGain(target,effect)
    local jp_value = target:getJobPointValue(tpz.jp.BRAZEN_RUSH_EFFECT)

    target:addMod(tpz.mod.ATTACK, 4 * jp_value)
    target:addMod(tpz.mod.DOUBLE_ATTACK, effect:getPower())
end

function onEffectTick(target,effect)
    local prevPower = effect:getPower()
    local nextPower = prevPower - 10

    target:delMod(tpz.mod.DOUBLE_ATTACK, prevPower)
    effect:setPower(nextPower)
    target:addMod(tpz.mod.DOUBLE_ATTACK, nextPower)
end

function onEffectLose(target,effect)
    local jp_value = target:getJobPointValue(tpz.jp.BRAZEN_RUSH_EFFECT)

    target:delMod(tpz.mod.ATTACK, 4 * jp_value)
    target:delMod(tpz.mod.DOUBLE_ATTACK, effect:getPower())
end