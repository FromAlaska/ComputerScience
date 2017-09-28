import sys
import math
print sys.argv

intervalX = input("Enter x: ")
intervalY = input("Enter y: ")

t0 = ((-16*pow(intervalX,2))+109*(intervalX))
print"S(t0)= ", t0
print"\n"

t1 = ((-16*pow(intervalY,2))+109*(intervalY))
print"S(t1)= ", t1
print"\n"

AverageVelocity= (t1-t0)/(intervalY-intervalX)
print "Average Velocity: ", AverageVelocity
