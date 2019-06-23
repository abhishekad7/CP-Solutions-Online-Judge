"""
n = int(input().strip())
last = pow(10, n-1) - 1
mx = pow(10, n)
lis = []
for i in range(9, 0, -1):
	if mx % i == 0:
		lis.append(i)
		
mx-=1
l = len(lis) - 1
ans = 0
for i in range(l, -1, -1):
	nxt = mx//lis[i]
	cnt = nxt - last
	last = nxt
	ans += cnt * (i+1)
	
print(ans)

"""

# Commented solution is also correct

n = int(input().strip())
print('14' if (n==1) else ('155' if (n==2) else '1575'+'0'*(n-3)))
