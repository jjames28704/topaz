-----------------------------------
--
-- tpz.effect.SENTINEL
--
-----------------------------------
require("scripts/globals/status")
-----------------------------------

function onEffectGain(target,effect)
    local jp_value = target:getJobPointValue(tpz.jp.SENTINEL_EFFECT)
    target:addMod(tpz.mod.UDMGPHYS,-effect:getPower())
    target:addMod(tpz.mod.ENMITY, 100 + jp_value)
    target:addMod(tpz.mod.ENMITY_LOSS_REDUCTION, effect:getSubPower())
end

function onEffectTick(target,effect)
   local power = effect:getPower()
   local decayby = 0
   -- Damage reduction decays until 50% then stops
   if (power > 50) then
      -- final tick with feet just has to be odd.
      if (power == 55) then
         decayby = 5
      -- decay by 8% per tick
      else
         decayby = 8
      end
      effect:setPower(power-decayby)
      target:delMod(tpz.mod.UDMGPHYS,-decayby)
   end
end

function onEffectLose(target,effect)
   local jp_value = target:getJobPointValue(tpz.jp.SENTINEL_EFFECT)
    target:delMod(tpz.mod.UDMGPHYS,-effect:getPower())
    target:delMod(tpz.mod.ENMITY, 100 + jp_value)
    target:delMod(tpz.mod.ENMITY_LOSS_REDUCTION, effect:getSubPower())
end