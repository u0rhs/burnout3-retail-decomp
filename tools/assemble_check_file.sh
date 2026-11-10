#!/bin/bash
set -e
cd "$(dirname "$0")/.."

AS_FLAGS="-EL -march=r5900 -mabi=o64 -G 0 -no-pad-sections -I . -I assembly/include"

s="$1"
o="$2"
mkdir -p "$(dirname "$o")"
mips-linux-gnu-as $AS_FLAGS -o "$o" "$s"
echo "assembled: $o"
