#Combs through a dictionary separating out words of three or more letters into files with only that many letters
#Ex. it will generate a file of only words of length three, then only words with length four, and so on

import sys

filename = sys.argv[1]
print filename
input = open(filename, 'r')

_3 = open("three_words.txt", 'w')
_4 = open("four_words.txt", 'w')
_5 = open("five_words.txt", 'w')
_6 = open("six_words.txt", 'w')
_7 = open("seven_words.txt", 'w')
_8 = open("eight_words.txt", 'w')
_9 = open("nine_words.txt", 'w')
_10 = open("ten_words.txt", 'w')
x = input.readline()
while(x):
	if len(x) ==4:
		_3.write(x)
	elif len(x) ==5:
		_4.write(x)
	elif len(x) ==6:
		_5.write(x)
	elif len(x) ==7:
		_6.write(x)
	elif len(x) ==8:
		_7.write(x)
	elif len(x) ==9:
		_8.write(x)
	elif len(x) ==10:
		_9.write(x)
	elif len(x) ==11:
		_10.write(x)
	else:
		pass
	x = input.readline()
input.close()
_3.close()
_4.close()
_5.close()
_6.close()
_7.close()
_8.close()
_9.close()
_10.close()
