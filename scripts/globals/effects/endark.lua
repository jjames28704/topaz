-----------------------------------
--
--
--
-----------------------------------
require("scripts/globals/status")
-----------------------------------

function onEffectGain(target,effect)
    local jp_value = target:getJobPointValue(tpz.jp.ENDARK_EFFECT)
    target:addMod(tpz.mod.ENSPELL,8)
    target:addMod(tpz.mod.ENSPELL_DMG,effect:getPower() + jp_value)
    target:addMod(tpz.mod.ATT,jp_value)
    target:addMod(tpz.mod.ACC,jp_value)
end

function onEffectTick(target,effect)
end

function onEffectLose(target,effect)
    local jp_value = target:getJobPointValue(tpz.jp.ENDARK_EFFECT)
    target:setMod(tpz.mod.ENSPELL_DMG,0)
    target:setMod(tpz.mod.ENSPELL,0)
    target:delMod(tpz.mod.ATT, jp_value)
    target:delMod(tpz.mod.ACC, jp_value)
end