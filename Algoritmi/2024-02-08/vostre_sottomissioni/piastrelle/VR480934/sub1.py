import resource, sys
resource.setrlimit(resource.RLIMIT_STACK, (2**29,-1))
sys.setrecursionlimit(10**6)
MOD = 1_000_000_007

def fibonacci(n):
    a, b = 0, 1
    for _ in range(n):
        a,b = b, (a+b) % MOD
    return a

def tile(tile_sequence):
    return ''.join(str(tile) for tile in tile_sequence)

def counting(n):
    dp = [0] * (n+1)
    dp[0], dp[1] = 1, 1
    for i in range(2, n + 1):
        dp[i] = (dp[i-1] + dp[i-2]) % MOD
    return dp[n]

def ranking(n, r):
    tile_string = tile(r)
    rank = 0
    fib = fibonacci(n+1)

    for i in range(n):
        if tile_string[i] == '2':
            rank += fib
            i += 1
        fib = (fib - fibonacci(n-1)) % MOD
    return rank

def unranking(n, r):
    tile_sequence = []
    fib = fibonacci(n + 1)
    while n > 0:
        if r >= fib:
            tile_sequence.append(2)
            r -= fib
            n -= 2
        else:
            tile_sequence.append(1)
            n -= 1
        fib = fibonacci(n+1)
    return tile_sequence


def main():
    T = int(input())
    for _ in range(T):
        n, c, r, u = map(int, input().split())
        counts = [counting(n) for _ in range(c)]
        ranks = [ranking(n, input().strip()) for _ in range(r)]
        unranked = [unranking(n, int(input())) for _ in range(u)]

        for count in counts:
            print(count)
        for rank in ranks:
            print(rank)
        for r in unranked:
            print(' '.join(map(str,r)))

if __name__ == "__main__":
    main()

