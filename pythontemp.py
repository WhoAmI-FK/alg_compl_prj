import matplotlib.pyplot as plt

with open("./resultstemp.txt") as sfd:
    next(sfd)
    sbs = sfd.read().splitlines()
    scs = [
        list(map(int, x.split()))
        for x in sbs
    ]
    sds = list(zip(*scs))

ssize, sinsert, smerge, squick, sheap = sds    
plt.title("Closer Comparison of merge and heap sorts")
plt.plot(ssize, smerge, label='mergesort')
plt.plot(ssize, sheap, label='heapsort')
plt.xlabel('array size')
plt.ylabel('time (in nanoseconds)')
plt.legend()
plt.savefig("overviewtemp.png")