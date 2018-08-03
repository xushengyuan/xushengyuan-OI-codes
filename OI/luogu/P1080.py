
def t3(element):
    return element[2]

n=int(input())
x,y=[int(x)for x in input().split()];
data=[]
for i in range(n):
    l,r=[int(x)for x in input().split()]
    data.append((l,r,l*r))
data.sort(key=t3)
_max=0
cot=x
for i in range(n):
    _max=max(cot//data[i][1],_max)
    cot*=data[i][0];
print(_max)