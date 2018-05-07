#!/opt/anaconda/bin/python
import shutil
import sys
import os

print(sys.argv)

filename = [f for f in sys.argv[1:] if '-' not in f][0]
flags = [f for f in sys.argv[1:] if f != filename]

if not filename.endswith('.cpp') and not filename.endswith('.py'):
    if any('p' in f for f in flags):
        filename += '.py'
    else:
        filename += '.cpp'
filepath = os.path.join(os.getcwd(), filename)

if os.path.isfile(filepath):
    print('FILE EXISTS!')
    print('Exiting...')
    sys.exit(0)

if filename.endswith('.cpp'):
    templatepath = '~/cp/templates/cpp_template.cpp'
else:
    templatepath = '~/cp/templates/codejam.py'

if any('i' in f for f in flags):
    templatepath = '~/cp/templates/icpc.cpp'
elif any('j' in f for f in flags):
    templatepath = '~/cp/templates/codejam.cpp'

instruction = 'cp {0} {1}'.format(templatepath, filepath)
print(instruction)
os.system(instruction)

vim = any('v' in f for f in flags)
os.system('{0} {1}'.format('nvim' if vim else 'subl', filepath))

