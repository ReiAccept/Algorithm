def fuck0(s):
    if s=='0': return '0'
    return str(int(s[::-1]))

def rev(s):
    if '.' in s:
        a, b = s.split('.')
        return fuck0(a) + '.' + fuck0(fuck0(fuck0(b)))
    if '/' in s:
        a, b = s.split('/')
        return fuck0(a) + '/' + fuck0(b)
    if '%' in s:
        return fuck0(s[:-1]) + '%'
    return fuck0(s)

print(rev(input()))