import timeit
import random as rand

matrix = int(input())

a = [[rand.random()*5 for i in range(matrix)] for j in range(matrix)]

b = [[rand.random()*5 for t in range(matrix)] for l in range(matrix)]

ans = [[0 for m in range(matrix)] for p in range(matrix)]

start = timeit.default_timer()
for i in range(matrix):
    for j in range(matrix):
        for k in range(matrix):
            ans[i][j] += a[i][k]*b[k][j]

end = timeit.default_timer()

print("Meat portion Time : ", end-start)
