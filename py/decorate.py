def bold(fn):
    def mkbold(s):
        return '<b>'+fn(s)+'</b>'
    return mkbold

@bold
def fun(s='hello'):
    return s

print fun(s='a')
