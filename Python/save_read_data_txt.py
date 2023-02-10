import os
import copy

# 'r'	It opens a file for reading only.
# 'w'	It opens a file for writing. If the file exists, it overwrites it, otherwise, it creates a new file.
# 'a'	It opens a file for appending only. If the file doesn’t exist, it creates the file.
# 'x'	It creates a new file. If the file exists, it fails.
# '+'	It opens a file for updating.
# 't'   Default mode
# 'b'   Binary mode


folder='E:\\Pythonproject\\LearningNotes\\'
fname='sig_read.txt'

fpath=folder+fname
f = open(fpath, 'r')
#data1 = f.read().splitlines()
data1 = f.read() # "1.xxx\n0.xxx\n...." read all data in a string
data2 = f.read()
# after read() or readline(), f has already been read, return empty, so data2=''
f.close()

with open(fpath,'r') as f:
    data2 = f.read().splitlines() # read number in list[500]
    f.close()

with open(fpath,'r') as f:
    data3 = f.readlines() # read number in list[500]
    f.close()
