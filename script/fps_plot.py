import matplotlib.pyplot as plt
import numpy as np

log_file = open('../build/fps_log.csv')
x, y = np.loadtxt(log_file, delimiter=',', unpack=True).tolist()

# Skip initial outliers
x = x[2:]
y = y[2:]

plt.plot(x,y)
plt.show()