-----------------------------------
-- tpz.effects.COUNTERSTANCE
-- DEF is removed in core as equip swaps can mess this up otherwise!
-----------------------------------
require("scripts/globals/status")
-----------------------------------

function onEffectGain(target,effect)
    local jp_value = target:getJobPointValue(tpz.jp.COUNTERSTANCE_EFFECT)
    target:addMod(tpz.mod.COUNTER,effect:getPower())
    target:addMod(tpz.mod.DEX, jp_value * 2 )
end

function onEffectTick(target,effect)
end

function onEffectLose(target,effect)
    local jp_value = target:getJobPointValue(tpz.jp.COUNTERSTANCE_EFFECT)
    target:delMod(tpz.mod.COUNTER,effect:getPower())
    target:delMod(tpz.mod.DEX, jp_value * 2)
end