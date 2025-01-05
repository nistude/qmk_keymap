#!/usr/bin/env bash

set -o errexit

FLASH=false

while getopts "fh" opt; do
    case $opt in
        f)
            FLASH=true
            ;;
        *)
            echo "Usage: $0 [-f] [-h]"
            echo "  -f: Flash the board after building"
            exit 1
            ;;
    esac
done

if [ $FLASH = true ]; then
    qmk flash
else
    qmk compile
fi
