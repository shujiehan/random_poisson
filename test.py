import time
from random_poisson import RandomPoisson

r = RandomPoisson(1)
sum_ = 0
start = time.time()
list_ = r.multiplePoisson(1.0, 100000)
sum_ = sum(list_)
print((time.time() - start)*1000000)
print(sum_)

list_ = r.multiplePoisson(1.0, 100000)
sum_ = sum(list_)
print((time.time() - start)*1000000)
print(sum_)
#for i in range(100000):
#    k = r.poisson(1.0) 
#    sum_ += k
