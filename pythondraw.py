import matplotlib.pyplot as plt

with open("./results.txt") as fd:
    next(fd)
    bs = fd.read().splitlines()
    cs = [
        list(map(int, x.split()))
        for x in bs
    ]
    ds = list(zip(*cs))

size, insert, merge, quick, heap = ds

#plt.plot(size, insert)
plt.plot(size, merge, label='mergesort')
plt.plot(size, quick, label='quick')
plt.plot(size, heap, label='heapsort')
plt.xlabel('array size')
plt.ylabel('time (in nanoseconds)')
plt.legend()
#print("merge: ",merge)
#print("insert: ", insert)
#print("quick: ", quick)
#print("heap: ", heap)
plt.savefig("pic.png")