-----------------------------------
--
--     tpz.effect.MIGHTY_STRIKES
--
-----------------------------------
require("scripts/globals/status")
-----------------------------------

function onEffectGain(target,effect)
    local jp_value = target:getJobPointValue(tpz.jp.MIGHTY_STRIKES_EFFECT)
    target:addMod(tpz.mod.CRITHITRATE,100)
    target:addMod(tpz.mod.ACC, jp_value * 2)
    target:addMod(tpz.mod.RACC, jp_value * 2)
end

function onEffectTick(target,effect)
end

function onEffectLose(target,effect)
    local jp_value = target:getJobPointValue(tpz.jp.MIGHTY_STRIKES_EFFECT)
    target:addMod(tpz.mod.CRITHITRATE,-100)
    target:delMod(tpz.mod.ACC, jp_value * 2)
    target:delMod(tpz.mod.RACC, jp_value * 2)
end