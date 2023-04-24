import sys
import numpy as np
import matplotlib.pyplot as plt


file_data_1 = sys.argv[1]  # Archivo con resultados .txt (sys.argv[0] nombre del archivo al igual que c++)
file_data_2 = sys.argv[2]
figure_name = sys.argv[3]

markersize = 3
elinewidth = 1

# Extract data from txt files
# title = np.loadtxt(file_data_1, dtype='str', max_rows=1)
title = ['N', 'mean eigen', 'sigma eigen', 'mean simple', 'sigma  simple']
data_1 = np.loadtxt(file_data_1, dtype=np.float64, skiprows=0, delimiter=',')
data_2 = np.loadtxt(file_data_2, dtype=np.float64, skiprows=0, delimiter=',')

x = data_1[:, 0]
# Normalization
wall_clock_time_eigen_N10_O0 = data_1[0, 1]
data_1[:, 1:-1] = data_1[:, 1:-1]/wall_clock_time_eigen_N10_O0
data_2[:, 1:-1] = data_2[:, 1:-1]/wall_clock_time_eigen_N10_O0


# Plot

plt.ylabel("wall-clock / wall-clock(eigen(N=10,-O0)) $[s/s]$")
plt.xlabel(title[0])
scientitic_notation = "{:.3e}".format(wall_clock_time_eigen_N10_O0)
plt.title(f"Weak Scaling with wall-clock(eigen(N=10,-O0) = {scientitic_notation}")
plt.errorbar(x, data_1[:, 1], yerr=data_1[:, 2], fmt='^', markersize=markersize,
             elinewidth=elinewidth, label=title[1]+' - 00')
plt.errorbar(x, data_1[:, 3], yerr=data_1[:, 4], fmt='s', markersize=markersize,
             elinewidth=elinewidth, label=title[3]+' - 00')
plt.errorbar(x, data_2[:, 1], yerr=data_2[:, 2], fmt='o', markersize=markersize,
             elinewidth=elinewidth, label=title[1]+' - 03')
plt.errorbar(x, data_2[:, 3], yerr=data_2[:, 4], fmt='x', markersize=markersize,
             elinewidth=elinewidth, label=title[3]+' - 03')

plt.legend()
plt.grid(linestyle='--', linewidth=0.3)
plt.savefig(figure_name, format="pdf", bbox_inches="tight")
# plt.show()

# Bibliography
# https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.grid.html
# https://www.scaler.com/topics/python-scientific-notation/
# https://www.digitalocean.com/community/tutorials/python-command-line-arguments
