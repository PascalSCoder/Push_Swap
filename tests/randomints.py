import random
import sys

if len(sys.argv) > 1:
	number_count = int(sys.argv[1])
else:
	number_count = 5

pile = list(range(number_count))
random.shuffle(pile)

file = open("numbers.txt", "w")
for i in pile:
	file.write(i.__str__() + " ")
