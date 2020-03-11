-----------------------------------
--
--
--
-----------------------------------
require("scripts/globals/status")
-----------------------------------

function onEffectGain(target,effect)
    local jp_value = target:getJobPointValue(dsp.jp.SHARPSHOT_EFFECT)
    target:addMod(dsp.mod.DEF, jp_value * 3)
    target:addMod(dsp.mod.COUNTER,(target:getMod(dsp.mod.ZANSHIN)/4))
end

function onEffectTick(target,effect)
end

function onEffectLose(target,effect)
    local jp_value = target:getJobPointValue(dsp.jp.SHARPSHOT_EFFECT)
    target:delMod(dsp.mod.DEF, jp_value * 3)
    target:delMod(dsp.mod.COUNTER,(target:getMod(dsp.mod.ZANSHIN)/4))
end
