t=int(raw_input())
while t>0:
    s = raw_input()
    if '101' in s or '010' in s:
        print "Good"
    else:
        print "Bad"
    t=t-1
