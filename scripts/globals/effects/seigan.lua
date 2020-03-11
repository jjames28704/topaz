-----------------------------------
--
--
--
-----------------------------------
require("scripts/globals/status")
-----------------------------------

function onEffectGain(target,effect)
    local jp_value = target:getJobPointValue(tpz.jp.SHARPSHOT_EFFECT)
    target:addMod(tpz.mod.DEF, jp_value * 3)
    target:addMod(tpz.mod.COUNTER,(target:getMod(tpz.mod.ZANSHIN)/4))
end

function onEffectTick(target,effect)
end

function onEffectLose(target,effect)
    local jp_value = target:getJobPointValue(tpz.jp.SHARPSHOT_EFFECT)
    target:delMod(tpz.mod.DEF, jp_value * 3)
    target:delMod(tpz.mod.COUNTER,(target:getMod(tpz.mod.ZANSHIN)/4))
end
