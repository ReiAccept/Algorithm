import base64

def cov64(s):
    while((s[0:5]!='flag{') or (s[-1]!='}')):
        s=base64.b64decode(s).decode()
    return s

print(cov64(input()))