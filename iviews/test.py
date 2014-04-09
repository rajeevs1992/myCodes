h = [0,0,0,0,0,0,0,0,0,0]
def getnum(n):
    for i in range(1, n+1):
        for j in range(0,10):
            h[j] += str(i).count(str(j))
getnum(int(raw_input()))
for i in h:
    print i
