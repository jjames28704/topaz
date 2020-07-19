-----------------------------------
--
--     tpz.effect.MEIKYO_SHISUI
--
-----------------------------------

function onEffectGain(target,effect)
    local jp_value = target:getJobPointValue(tpz.jp.MEIKYO_SHISUI_EFFECT)
    target:addMod(tpz.mod.SKILLCHAINDMG, 2 * jp_value)
end

function onEffectTick(target,effect)
end

function onEffectLose(target,effect)
    local jp_value = target:getJobPointValue(tpz.jp.MEIKYO_SHISUI_EFFECT)
    target:delMod(tpz.mod.SKILLCHAINDMG, 2 * jp_value)
end