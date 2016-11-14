import sys
#for line in sys.stdin:
def cross(ax,ay,bx,by):
	return ax*by-ay*bx

def check(ax,ay,bx,by,cx,cy,dx,dy):
	a=cross(dx-ax,dy-ay,bx-ax,by-ay)
	b=cross(ax-bx,ay-by,cx-bx,cy-by)
	c=cross(bx-cx,by-cy,dx-cx,dy-cy)
	d=cross(cx-dx,cy-dy,ax-dx,ay-dy)
	if a*b<0 or a*c<0 or a*d<0:
		return False
	else:
		return True

if __name__=="__main__":
	"""while True:
		line=raw_input()
	"""
	for line in sys.stdin:
		a=map(float,line.split(","))
		if check(a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7]):
			print "YES"
		else:
			print "NO"
