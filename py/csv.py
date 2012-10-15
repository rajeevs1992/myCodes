file=open("data.txt")
out=open("out.csv","w")
data=file.readline()
temp=''
i=0
while(data):
	temp=data.split()
	str=''
	l=len(temp)
	while(i<l):
		if l==23:
			if i==4:
				str=str+',,'
		elif l==22:
			if i==3:
				str=str+',,,'
		elif l==21:
			if i==2:
				str=str+',,,,'
		elif l==24:
			if i==5:
				str=str+','
		str=str+temp[i]+','
		i=i+1
	print str
	str=str+'\n'
	flag=raw_input('data y or n?')
	if flag=='y':
		out.write(str)
		print 'written'
	temp=''
	data=''
	data=file.readline()
	i=0
file.close()
out.close()
