-----------------------------------
--
--
--
-----------------------------------

function onEffectGain(target,effect)
    local jp_value = target:getJobPointValue(tpz.jp.SOUL_VOICE_EFFECT)
    target:addMod(tpz.mod.SONG_SPELLCASTING_TIME, 2 * jp_value)
end

function onEffectTick(target,effect)
end

function onEffectLose(target,effect)
    local jp_value = target:getJobPointValue(tpz.jp.SOUL_VOICE_EFFECT)
    target:delMod(tpz.mod.SONG_SPELLCASTING_TIME, 2 * jp_value)
end