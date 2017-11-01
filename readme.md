# My Planck layout [WIP]

Optimized for Slovak keymap

## Deployment notes (to self)

Official docs at <https://docs.qmk.fm/features.html>

Prerequisites for Fedora 23:

```
# yum install gcc unzip wget zip avr-gcc avr-binutils avr-libc dfu-programmer dfu-util arm-none-eabi-gcc arm-none-eabi-binutils-cs arm-none-eabi-newlib
```

Clone the repo:

```
$ git clone https://github.com/jackhumbert/qmk_firmware.git
```

Contents iof this repo should go to **qmk_firmware/keyboards/planck/keymaps/pondrejk/**. Then form **qmk_firmware/** do:

```
$ sudo make planck/rev4:pondrejk:dfu
```

## TODO

Create a language file for Slovak keymap, see **qmk_firmware/quantum/keymap_extras**.
