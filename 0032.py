import sys
rec=rho=0
for line in sys.stdin:
	a,b,c=map(int,line.split(","))
	if a==b:
		rho+=1
	elif a*a+b*b==c*c:
		rec+=1
print rec
print rho
