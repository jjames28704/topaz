-----------------------------------
--
--
--
-----------------------------------
require("scripts/globals/status")
-----------------------------------

function onEffectGain(target,effect)
    local jp_value = target:getJobPointValue(tpz.jp.ENLIGHT_EFFECT)
    target:addMod(tpz.mod.ENSPELL,7)
    target:addMod(tpz.mod.ENSPELL_DMG,effect:getPower() + jp_value)
    target:addMod(tpz.mod.ACC, jp_value * 2)
end

function onEffectTick(target,effect)
end

function onEffectLose(target,effect)
    local jp_value = target:getJobPointValue(tpz.jp.ENLIGHT_EFFECT)
    target:setMod(tpz.mod.ENSPELL_DMG,0)
    target:setMod(tpz.mod.ENSPELL,0)
    target:delMod(tpz.mod.ACC, jp_value * 2)
end