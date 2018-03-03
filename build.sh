#!/bin/bash
docker run -e keymap=shia -e keyboard=preonic --rm -v $('pwd'):/qmk:rw edasque/qmk_firmware
