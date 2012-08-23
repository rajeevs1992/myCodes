import sys
handle=open(sys.argv[2])
count=0
word=handle.readline()
while(word):
	if cmp(word[:len(word)-1],sys.argv[1])==0:
		count+=1
	word=handle.readline()
print count

