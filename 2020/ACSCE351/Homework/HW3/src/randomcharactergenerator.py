import string
import random

with open("/home/spacecookies/Documents/gitFiles/ComputerScience/2020/ACSCE351/Homework/HW3/Scripts/randomlyGeneratedString", "a") as my_file:
	for i in range(1,1000000):
		my_file.write(random.choice(string.letters))
