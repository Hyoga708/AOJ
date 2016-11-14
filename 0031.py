import sys

for line in sys.stdin:
	x=int(line)
	out=1
	ret=""
	while x:
		if x&1:
			ret+=" "+str(out)
		x/=2
		out*=2
	print ret[1::]
