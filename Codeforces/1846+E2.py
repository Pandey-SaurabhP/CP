
def root(x):
    if x <= 1: return x

    st = 2
    ed = x // 2
    
    ans = -1

    while(st <= ed):
        mid = (st + ed) // 2

        sq = mid * mid

        if(sq == x): return mid
        elif(sq < x): 
            st = mid + 1
            ans = mid
        else:
            ed = mid - 1
    
    return ans

def isPerfectSquare(x):

    y = root(x)

    if(y * y == x):
        return True
    
    return False

def fastPower(b, e):

    ans = 1

    while(e >= 1):

        if(e % 2 == 1):
            ans *= b
            e -= 1

        b *= b
        e //= 2
    
    return ans

def oneDistance(n):
    d = (4 * n) - 3

    if(isPerfectSquare(d) == False):
       return 0
    
    sq = root(d)
    sq -= 1

    if (sq % 2 == 1): return 0
    if(sq / 2 <= 1): return 0

    return 1

def binarySearch(x, l):
    n = len(l)

    lo = 0
    hi = n - 1

    while(lo < hi):
        mid = (lo + hi) // 2

        if(l[mid] == x):
            return 1
        elif(l[mid] > x):
            hi = mid
        else:
            lo = mid + 1
    
    return 0


lim2 = 1000000
lim = 10000000000000000000

l = []

for b in range(2, lim2 + 1):

    for n in range(3, 64):
        ans = fastPower(b, n)

        if(ans <= lim):
            l.append(ans)


l.sort()

for i in range(0, 100):
    print(l[i], end = ' ')
print()


t = int(input())

while(t > 0):
    n = int(input())

    # x = (4 * n) - 3
    # print(root(x), root(x) * root(x), x)

    if(oneDistance(n)):
        print("YES")
    elif(binarySearch(n, l) == True):
        print("YES")
    else:
        print("NO")

    t -= 1


    
    