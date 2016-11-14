n=input()
for t in xrange(n):
	a=map(int,raw_input().split())
	pos=range(1,11)
	for i in xrange(len(a)):
		pos[a[i]-1]=i
	left=right=-1
	for i in xrange(len(pos)):
		if(left<pos[i]):
			left=pos[i]
		elif(right<pos[i]):
			right=pos[i]
		else:
			print "NO"
			break
	else:
		print "YES"
