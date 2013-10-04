temp = raw_input()
temp = temp.split()
n = int(temp[0])
k = int(temp[1])
h = {}
count = 0
for i in range(0,k):
    c = raw_input()
    if ' ' in c:
        c = c.split()
        j = int(c[1])
        if j in h:
            if h[j] == 1:
                count = count - 1
                h[j] = 0
            else:
                count = count + 1
                h[j] = 1
        else:
            count = count + 1
            h[j] = 1
    else:
        h = {}
        count = 0
    print count

