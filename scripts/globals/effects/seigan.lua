-----------------------------------
--
--
--
-----------------------------------
require("scripts/globals/status")
-----------------------------------

function onEffectGain(target,effect)
    local jp_value = target:getJobPointValue(tpz.jp.SHARPSHOT_EFFECT)
    local counterRate = target:getMod(tpz.mod.ZANSHIN) * 0.25
    counterRate = math.min(math.max(0,counterRate), 25 + target:getMod(tpz.mod.HASSO_SEIGAN_ZANSHIN_CAP))
    
    target:addMod(tpz.mod.DEF, jp_value * 3)
    target:addMod(tpz.mod.COUNTER,counterRate)
end

function onEffectTick(target,effect)
end

function onEffectLose(target,effect)
    local jp_value = target:getJobPointValue(tpz.jp.SHARPSHOT_EFFECT)
    local counterRate = target:getMod(tpz.mod.ZANSHIN * 0.25
    counterRate = math.min(math.max(0,counterRate), 25 + target:getMod(tpz.mod.HASSO_SEIGAN_ZANSHIN_CAP))
    
    target:delMod(tpz.mod.DEF, jp_value * 3)
    target:delMod(tpz.mod.COUNTER,counterRate)
end
