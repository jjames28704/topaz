-----------------------------------
--
--     tpz.effect.FOCUS
--
-----------------------------------
require("scripts/globals/status")
-----------------------------------

function onEffectGain(target,effect)
   local jp_value = target:getJobPointValue(tpz.jp.FOCUS_EFFECT)
   target:addMod(tpz.mod.ACC,effect:getPower() + jp_value)
end

function onEffectTick(target,effect)
end

function onEffectLose(target,effect)
   local jp_value = target:getJobPointValue(tpz.jp.FOCUS_EFFECT)
   target:delMod(tpz.mod.ACC,effect:getPower() + jp_value)
end