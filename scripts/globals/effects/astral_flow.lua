-----------------------------------
--
--
--
-----------------------------------

function onEffectGain(target,effect)
    target:recalculateAbilitiesTable()
    if target:isPC() then
        local jp_value = target:getJobPointValue(tpz.jp.ASTRAL_FLOW_EFFECT) * 5
        if jp_value > 0 then
            target:addPetMod(tpz.mod.STR, jp_value)
            target:addPetMod(tpz.mod.DEX, jp_value)
            target:addPetMod(tpz.mod.VIT, jp_value)
            target:addPetMod(tpz.mod.AGI, jp_value)
            target:addPetMod(tpz.mod.INT, jp_value)
            target:addPetMod(tpz.mod.MND, jp_value)
            target:addPetMod(tpz.mod.CHR, jp_value)
        end
    end
end

function onEffectTick(target,effect)
end

function onEffectLose(target,effect)
    target:recalculateAbilitiesTable()
    if target:isPC() then
        local jp_value = target:getJobPointValue(tpz.jp.ASTRAL_FLOW_EFFECT) * 5
        if jp_value > 0 then
            target:delPetMod(tpz.mod.STR, jp_value)
            target:delPetMod(tpz.mod.DEX, jp_value)
            target:delPetMod(tpz.mod.VIT, jp_value)
            target:delPetMod(tpz.mod.AGI, jp_value)
            target:delPetMod(tpz.mod.INT, jp_value)
            target:delPetMod(tpz.mod.MND, jp_value)
            target:delPetMod(tpz.mod.CHR, jp_value)
        end
    end
end