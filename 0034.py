import sys
for line in sys.stdin:
#while True:
#	line=raw_input()
	l=map(int,line.split(","))
	dis=l[10]/float(l[10]+l[11])*sum(l[:10])
	suml=0
	for i in xrange(10):
		suml+=l[i]
		if dis<=suml:
			print i+1
			break

