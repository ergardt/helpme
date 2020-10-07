#gamma0 = float(input())
#ro0 = float(input())
#p0 = float(input())
#u0 = float(input())
#gamma3 = float(input())
#c3 = float(input())
#p3 = float(input())
#u3 = float(input())


import numpy as np
import math

gamma0 = 1.66666666
ro0 = 0.00001
p0 = 3848
u0 = 0
gamma3 = 1.4
c3 = 25324.8
p3 = 3040000000
u3 = 0


def equate(b1, b2, b3, b4, b5, b6, b7, y):
    return b1 * y**(2*n) + b2 * y**(n+2) + b3 * y**(n+1) + b4 * y**n + b5 * y**2 + b6 * y + b7


ro3 = gamma3 * p3 / (math.pow(c3, 2))

alpha0 = float((gamma0 + 1)/(gamma0 - 1))
n = float(2 * gamma3/(gamma3 - 1))
mu = float((u3 - u0)*(math.sqrt(((gamma0 - 1) * ro0) / (2 * p0))))
nu = float(2 / (gamma3 -1) * (math.sqrt((gamma3 * (gamma0 -1) * p3 * ro0)/(2 * p0 * ro3))))
x = float(p3 / p0)
# z = float(math.pow((p1/ p3), (1/n)))


a1 = x ** 2
a2 = -alpha0 * nu ** 2 * x
a3 = 2 * alpha0 * nu * (mu + nu) * x
a4 = -(2 + (mu + nu) ** 2 * alpha0) * x
a5 = -(nu ** 2)
a6 = 2 * nu * (nu+mu)
a7 = -(mu+nu) ** 2 + 1

matrix = (a1, a2, a3, a4, a5, a6, a7)

print(matrix)

A = float(max(abs(a2), abs(a3), abs(a4), abs(a5), abs(a6), abs(a7)))
B = float(max(abs(a2), abs(a3), abs(a4), abs(a5), abs(a6), abs(a1)))
minBorder = float(abs(a7) / (abs(a7) + B))
maxBorder = 1 + A/a1


print("Грубая нижняя граница ", minBorder, "Грубая верхняя граница ", maxBorder)

#найдем число перемен знаков в последовательности коэфициентов

k = 0
for i in range(6):
    if matrix[i]*matrix[i+1] < 0:
        k += 1
print('Число перемен знаков', k)


#for i in np.arange(minBorder, maxBorder, 0.001):
    #if equate(a1, a2, a3, a4, a5, a6, a7, i)*equate(a1, a2, a3, a4, a5, a6, a7, i+0.001) < 0:
        #print('here', i, i+0.001)



while maxBorder - minBorder > 0.000000001:
    center = (maxBorder + minBorder) / 2
    if equate(a1, a2, a3, a4, a5, a6, a7, minBorder)*equate(a1, a2, a3, a4, a5, a6, a7, center) < 0:
        maxBorder = center
    else:
        if equate(a1, a2, a3, a4, a5, a6, a7, maxBorder)*equate(a1, a2, a3, a4, a5, a6, a7, center) < 0:
            minBorder = center

#print("Нижняя граница ", minBorder, "Верхняя граница ", maxBorder)
