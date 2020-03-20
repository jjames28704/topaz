-----------------------------------
--
--     tpz.effect.PROTECT
--
-----------------------------------
require("scripts/globals/status")
-----------------------------------

function onEffectGain(target,effect)
   local power = effect:getPower();
   if target:hasMod(tpz.mod.PROTECT_EFFECT) then
      power = power * (target:getMod(tpz.mod.PROTECT_EFFECT) / 100)
  end

   target:addMod(tpz.mod.DEF,power)
end

function onEffectTick(target,effect)
end

function onEffectLose(target,effect)
   local power = effect:getPower();
   if target:hasMod(tpz.mod.PROTECT_EFFECT) then
      power = power * (target:getMod(tpz.mod.PROTECT_EFFECT) / 100)
  end

   target:delMod(tpz.mod.DEF,power)
end