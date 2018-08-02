-----------------------------------
-- Area: Fort_Karugo-Narugo_[S]
-----------------------------------
require("scripts/globals/zone")
-----------------------------------

zones = zones or {}

zones[dsp.zone.FORT_KARUGO_NARUGO_S] =
{
    text =
    {
        ITEM_CANNOT_BE_OBTAINED  = 6381, -- You cannot obtain the item <item>. Come back after sorting your inventory.
        ITEM_OBTAINED            = 6387, -- Obtained: <item>.
        GIL_OBTAINED             = 6388, -- Obtained <number> gil.
        KEYITEM_OBTAINED         = 6390, -- Obtained key item: <keyitem>.
        SPONDULIX_SHOP_DIALOG    = 7203, -- Spondulix comes all the way from Boodlix's Emporium to help Tarutaru and Mithra. I can help you, too! You have gil, no?
        LOGGING_IS_POSSIBLE_HERE = 7670, -- Logging is possible here if you have
        NOTHING_OUT_OF_ORDINARY  = 7703, -- There is nothing out of the ordinary here.
        ITEM_DELIVERY_DIALOG     = 8109, -- Deliveries! We're open for business!
    },
    mob =
    {
        TIGRESS_STRIKES_WAR_LYNX = 17170645,
    },
    npc =
    {
        FORT_KN_INDESCRIPT_MARKINGS = 17171272,
    },
}

return zones[dsp.zone.FORT_KARUGO_NARUGO_S]