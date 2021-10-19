my keyboard configurations
--------------------------

- setup: <https://docs.qmk.fm/#/newbs_getting_started>
- configurator: <https://config.qmk.fm/#/preonic/rev3_drop/LAYOUT_ortho_5x12>
- flashing: <https://docs.qmk.fm/#/newbs_flashing>

## Preonic

> ln -s [...]/keyboards/preonic [...]qmk_firmware/keyboards/preonic/keymaps/pondrejk

test

> qmk compile -kb preonic/rev3_drop -km pondrejk

flash

> qmk flash -kb preonic/rev3_drop -km pondrejk


## Planck

> ln -s [...]/keyboards/planck [...]qmk_firmware/keyboards/planck/keymaps/pondrejk

test

> qmk compile -kb planck/rev3 -km pondrejk

flash

> qmk flash -kb planck/rev3 -km pondrejk

##
