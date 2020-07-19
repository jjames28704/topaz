-----------------------------------
-- Composure
-- Increases accuracy and lengthens recast time. Enhancement effects gained through white
-- and black magic you cast on yourself last longer.
-----------------------------------
require("scripts/globals/status")
-----------------------------------

function onEffectGain(target,effect)
    local jp_value = target:getJobPointValue(tpz.jp.COMPOSURE_EFFECT);
    print(jp_value);
    target:addMod(tpz.mod.ACC,15 + jp_value)
end

function onEffectTick(target,effect)
end

function onEffectLose(target,effect)
    local jp_value = target:getJobPointValue(tpz.jp.COMPOSURE_EFFECT);
    print(jp_value);
    target:delMod(tpz.mod.ACC,15 + jp_value)
end