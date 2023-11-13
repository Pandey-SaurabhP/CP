n, k = map(int, input().split())


def ncr(n, r):
    if r > n:
        return 0
    r = min(r, n - r)
    num = 1
    den = 1
    for i in range(r):
        num *= (n - i)
        den *= (i + 1)
    return num // den

def findSymm(n, i):
    if i == n: return 1
    
    if n % 2 == 0 and i % 2 == 0:
        return ncr(n // 2, i // 2)
    elif n % 2 == 0 and i % 2 == 1:
        return 0
    elif n % 2 == 1:
        return ncr(n // 2, i // 2)

ans = 0
a = []

symm = []


for i in range(0, k + 1):
    a.append(ncr(n, i))
    xyz = len(a) - 1
    symm.append(findSymm(n, i))

    a[xyz] -= symm[xyz]
    a[xyz] //= 2
    a[xyz] += symm[xyz]


# for i in range(0, k + 1):
#     print(i, ' : ', a[i])

st = set()

for i in range(k + 1):
    if (i, k - i) in st:
        continue

    if i > n or (k - i) > n:
        continue

    ans += (a[i] + a[k - i])

    st.add((i, k - i))
    st.add((k - i, i))

print(ans)
