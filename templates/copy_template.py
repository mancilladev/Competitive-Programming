#!/opt/anaconda/bin/python
import shutil
import sys
import os

print(sys.argv)
flags = sys.argv[2:]

filename = sys.argv[1]
if not filename.endswith('.cpp'):
    filename += '.cpp'
filepath = os.path.join(os.getcwd(), filename)

templatepath = '~/cp/templates/cpp_template.cpp'
if any('i' in f for f in flags):
    templatepath = '~/cp/templates/icpc.cpp'

os.system('cp {0} {1}'.format(templatepath, filepath))

vim = any('v' in f for f in flags)
os.system('{0} {1}'.format('nvim' if vim else 'subl', filepath))

