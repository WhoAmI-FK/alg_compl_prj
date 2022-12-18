import matplotlib.pyplot as plt

with open("./resultssmall.txt") as sfd:
    next(sfd)
    sbs = sfd.read().splitlines()
    scs = [
        list(map(int, x.split()))
        for x in sbs
    ]
    sds = list(zip(*scs))

ssize, sinsert, smerge, squick, sheap = sds    
plt.title("For small array sizes")
plt.plot(ssize, sinsert, label="insertionsort")
plt.plot(ssize, smerge, label='mergesort')
plt.plot(ssize, squick, label='quicksort')
plt.plot(ssize, sheap, label='heapsort')
plt.xlabel('array size')
plt.ylabel('time (in nanoseconds)')
plt.legend()
plt.savefig("overviewsm.png")