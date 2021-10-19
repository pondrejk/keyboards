my keyboard configurations
--------------------------

- setup: <https://docs.qmk.fm/#/newbs_getting_started>
- configurator: <https://config.qmk.fm/#/preonic/rev3_drop/LAYOUT_ortho_5x12>
- flashing: <https://docs.qmk.fm/#/newbs_flashing>

# Planck

`ln -s [...]/keyboards/planck [...]qmk_firmware/keyboards/planck/keymaps/pondrejk`

test

`qmk compile -kb planck/rev3 -km pondrejk`

flash

`qmk flash -kb planck/rev3 -km pondrejk`
