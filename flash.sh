#!/bin/bash

set -e

echo "Flashing left board..."
qmk flash

read -n 1 -s -r -p "Switch the USB cable to the right board and press any key..."
echo

echo "Flashing right board..."
qmk flash

echo "Done! Switch back to the left board."
