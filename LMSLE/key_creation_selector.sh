#!/bin/bash

OPTION=$(whiptail --title "GENERATE KEY FILE" --menu "Choose your option" 15 60 4 \
"1" "Generate 4-bit Key" \
"2" "Generate 8-bit Key" \
"3" "Generate 16-bit Key" \
"4" "Generate 32-bit Key" \
"5" "Get Special Key Online" 3>&1 1>&2 2>&3)

exitstatus=$?
case $OPTION in
    1) cd key_creation && ./4b_key;;
    2) cd key_creation && ./8b_key;;
    3) cd key_creation && ./16b_key;;
    4) cd key_creation && ./32b_key;;
    5) echo "Comming Soon";;
    *) echo "Invalid option. Quitting";;
esac

exit

