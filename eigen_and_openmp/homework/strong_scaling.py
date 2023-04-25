import sys
import numpy as np
import matplotlib.pyplot as plt


# Archivo con resultados .txt (sys.argv[0] nombre del archivo al igual que c++)
wall_clock_time_eigen_N10_O0 = np.array([sys.argv[1]]).astype(np.float64)[0]
file_data_1 = sys.argv[2] + '.txt'
figure_name = sys.argv[2] + '.pdf'

markersize = 3
elinewidth = 1

# Extract data from txt files
# title = np.loadtxt(file_data_1, dtype='str', max_rows=1)
title = ['Threads', 'mean eigen', 'sigma eigen']
data = np.loadtxt(file_data_1, dtype=np.float64, skiprows=0, delimiter=',')

x = data[:, 0]
# Normalization
data[:, 1:-1] = data[:, 1:-1]/wall_clock_time_eigen_N10_O0


# Plot

plt.ylabel("wall-clock / wall-clock(eigen(N=10,-O0)) $[s/s]$")
plt.xlabel(title[0])
scientitic_notation = "{:.3e}".format(wall_clock_time_eigen_N10_O0)
plt.title(f"Strong Scaling with wall-clock(eigen(N=10,-O0) = {scientitic_notation} [s]")
plt.errorbar(x, data[:, 1], yerr=data[:, 2], fmt='^', markersize=markersize,
             elinewidth=elinewidth, label=title[1])

plt.legend()
plt.grid(linestyle='--', linewidth=0.3)
plt.savefig(figure_name, format="pdf", bbox_inches="tight")
# plt.show()

# Bibliography
# https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.grid.html
# https://www.scaler.com/topics/python-scientific-notation/
# https://www.digitalocean.com/community/tutorials/python-command-line-arguments
