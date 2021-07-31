import random

number_count = 5

pile = []

pile = list(range(number_count))

random.shuffle(pile)

file = open("numbers.txt", "w")
for i in pile:
	file.write(i.__str__() + " ")
