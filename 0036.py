import sys
dic={"A":["11","11"],"B":["1","1","1","1"],"C":["1111"],"D":["01","11","10"],
		"E":["110","011"],"F":["10","11","01"],"G":["011","110"]}
s=[]
linecnt=0
for line in sys.stdin:
	if line=="\n" or line=="":
		continue
	linecnt+=1
	if linecnt<8:
		s.append(line.rstrip("\n"))
	else:
		s.append(line.rstrip("\n"))
		while s[0]=="00000000":
			del(s[0])
		while s[len(s)-1]=="00000000":
			del(s[len(s)-1])
		i=len(s[0])-1
		while i>=0:
			for l in xrange(len(s)):
				if s[l][i]=="1":
					break
			else:
				for l in xrange(len(s)):
					s[l]=s[l][0:i]+s[l][i+1:len(s[l])]
			i-=1
		for d in dic.keys():
			if dic[d]==s:
				print d
				break
		while len(s)>0:
			del(s[0])
		linecnt=0
