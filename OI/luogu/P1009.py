n=0
n=int(input())
s=0
t=1
for i in range(1,n+1):
    s+=t
    t*=i+1
print(s)
