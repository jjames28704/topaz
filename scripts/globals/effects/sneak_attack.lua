-----------------------------------
--
--     tpz.effect.SNEAK_ATTACK
--
-----------------------------------

function onEffectGain(target,effect)
    local jp_value = target:getJobPointValue(tpz.jp.SNEAK_ATTACK_EFFECT)
    target:addMod(tpz.mod.SNEAK_ATK_DEX, jp_value)
end

function onEffectTick(target,effect)
end

function onEffectLose(target,effect)
    local jp_value = target:getJobPointValue(tpz.jp.SNEAK_ATTACK_EFFECT)
    target:delMod(tpz.mod.SNEAK_ATK_DEX, jp_value)
end