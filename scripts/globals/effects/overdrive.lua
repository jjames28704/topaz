-----------------------------------
--
--     dsp.effect.OVERDRIVE
--
-----------------------------------
require("scripts/globals/status")

function onEffectGain(target, effect)
    target:addMod(tpz.mod.OVERLOAD_THRESH, 5000)
    local jp_value = target:getJobPointValue(tpz.jp.OVERDRIVE_EFFECT) * 5
    local pet = target:getPet()
    if pet then
        pet:setLocalVar("overdrive", 1)
        pet:addMod(tpz.mod.HASTE_MAGIC, 2500)
        pet:addMod(tpz.mod.MAIN_DMG_RATING, 30)
        pet:addMod(tpz.mod.RANGED_DMG_RATING, 30)
        pet:addMod(tpz.mod.ATTP, 50)
        pet:addMod(tpz.mod.RATTP, 50)
        pet:addMod(tpz.mod.ACC, 100)
        pet:addMod(tpz.mod.RACC, 100)
        pet:addMod(tpz.mod.EVA, 50)
        pet:addMod(tpz.mod.MEVA, 50)
        pet:addMod(tpz.mod.REVA, 50)
        pet:addMod(tpz.mod.DMG, -50)
        if jp_value then
            pet:addMod(tpz.mod.STR, jp_value)
            pet:addMod(tpz.mod.DEX, jp_value)
            pet:addMod(tpz.mod.VIT, jp_value)
            pet:addMod(tpz.mod.AGI, jp_value)
            pet:addMod(tpz.mod.INT, jp_value)
            pet:addMod(tpz.mod.MND, jp_value)
            pet:addMod(tpz.mod.CHR, jp_value)
        end
    end
end

function onEffectTick(target, effect)
end

function onEffectLose(target, effect)
    target:delMod(tpz.mod.OVERLOAD_THRESH, 5000)
    local jp_value = target:getJobPointValue(tpz.jp.OVERDRIVE_EFFECT) * 5
    local pet = target:getPet()
    if pet and pet:getLocalVar("overdrive") ~= 0 then
        pet:setLocalVar("overdrive", 0)
        pet:delMod(tpz.mod.HASTE_MAGIC, 2500)
        pet:delMod(tpz.mod.MAIN_DMG_RATING, 30)
        pet:delMod(tpz.mod.RANGED_DMG_RATING, 30)
        pet:delMod(tpz.mod.ATTP, 50)
        pet:delMod(tpz.mod.RATTP, 50)
        pet:delMod(tpz.mod.ACC, 100)
        pet:delMod(tpz.mod.RACC, 100)
        pet:delMod(tpz.mod.EVA, 50)
        pet:delMod(tpz.mod.MEVA, 50)
        pet:delMod(tpz.mod.REVA, 50)
        pet:delMod(tpz.mod.DMG, -50)
        if jp_value then
            pet:delMod(tpz.mod.STR, jp_value)
            pet:delMod(tpz.mod.DEX, jp_value)
            pet:delMod(tpz.mod.VIT, jp_value)
            pet:delMod(tpz.mod.AGI, jp_value)
            pet:delMod(tpz.mod.INT, jp_value)
            pet:delMod(tpz.mod.MND, jp_value)
            pet:delMod(tpz.mod.CHR, jp_value)
        end
    end
end