import numpy as np
import matplotlib.pyplot as plt


movies    = np.array([2, 2, 2, 3, 1, 1, 2, 3, 4, 1, 4])
years     = np.array([1999, 2000, 2001, 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009])
drownings = np.array([109, 102, 102, 98, 85, 95, 96, 98, 123, 94, 102])

fig, ax1 = plt.subplots()

color = 'tab:red'
ax1.set_xlabel('Years')
ax1.set_ylabel('Swimming pool drownings', color=color)
ax1.plot(years, drownings, color=color, marker='o')
ax1.tick_params(axis='y', labelcolor=color)
# ax1.yaxis.set_major_locator(plt.MaxNLocator(1))
plt.yticks((80, 120 , 160))


ax2 = ax1.twinx()  # instantiate a second axes that shares the same x-axis

color = 'tab:blue'
ax2.set_ylabel('Nicholas Cage', color=color)  # we already handled the x-label with ax1
ax2.plot(years, movies, color=color, marker='x')
ax2.tick_params(axis='y', labelcolor=color)
plt.yticks((0, 4 , 8))

fig.tight_layout()  # otherwise the right y-label is slightly clipped

plt.xticks(np.arange(min(years), max(years)+1, 1.0))

plt.show()
