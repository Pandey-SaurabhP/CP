n = int(input())
a = list(map(int, input().split()))

pre = []
pre.append(0)

for i in range(n):
    pre.append(a[i] + pre[i])

prepre = []
prepre.append(0)
for i in range(1, n + 1):
    prepre.append(pre[i] + prepre[i - 1])

# print(pre);
# print(prepre)

q = int(input())

while q > 0:
    l, r, k = map(int, input().split())
    
    ans = prepre[r] - prepre[l + k - 2]
    ans -= prepre[r - k]

    print(ans)
    q -= 1
