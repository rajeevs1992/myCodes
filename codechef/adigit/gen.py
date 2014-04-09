import random
f=open('in1','w')
s=''
for i in range(0,100000):
    n=random.randint(0,9)
    s=s+str(n)
f.write(s)
f.close()    
