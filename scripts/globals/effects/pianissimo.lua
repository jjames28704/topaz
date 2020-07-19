-----------------------------------
--
--
--
-----------------------------------

function onEffectGain(target,effect)
    local jp_value = caster:getJobPointValue(tpz.jp.PIANISSIMO_EFFECT)
    target:addMod(tpz.mod.SONG_SPELLCASTING_TIME, jp_value * 2)
end

function onEffectTick(target,effect)
end

function onEffectLose(target,effect)
    local jp_value = caster:getJobPointValue(tpz.jp.PIANISSIMO_EFFECT)
    target:delMod(tpz.mod.SONG_SPELLCASTING_TIME, jp_value * 2)
end