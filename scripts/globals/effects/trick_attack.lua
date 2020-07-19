-----------------------------------
--
-- tpz.effect.TRICK_ATTACK
--
-----------------------------------

function onEffectGain(target,effect)
    local jp_value = target:getJobPointValue(tpz.jp.TRICK_ATTACK_EFFECT)
    target:addMod(tpz.mod.TRICK_ATK_AGI, jp_value)
end

function onEffectTick(target,effect)
end

function onEffectLose(target,effect)
    local jp_value = target:getJobPointValue(tpz.jp.TRICK_ATTACK_EFFECT)
    target:delMod(tpz.mod.TRICK_ATK_AGI, jp_value)
end