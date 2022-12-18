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

plt.title("Overview of perfomance")
plt.plot(size, insert, label="insertionsort")
plt.plot(size, merge, label='mergesort')
plt.plot(size, quick, label='quicksort')
plt.plot(size, heap, label='heapsort')
plt.xlabel('array size')
plt.ylabel('time (in nanoseconds)')
plt.legend()
plt.savefig("overview.png")

plt.clf()
plt.title("Perfomance without insertionsort")
plt.plot(size, merge, label='mergesort')
plt.plot(size, quick, label='quicksort')
plt.plot(size, heap, label='heapsort')
plt.xlabel('array size')
plt.ylabel('time (in nanoseconds)')
plt.legend()
plt.savefig("ovnoins.png");

plt.clf()
plt.title("Comparison merge and heap sorts")
plt.plot(size, merge, label='mergesort')
plt.plot(size, heap, label='heapsort')
plt.xlabel('array size')
plt.ylabel('time (in nanoseconds)')
plt.legend()
plt.savefig("ovmerheap.png");