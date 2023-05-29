import sys
import numpy as np
import matplotlib.pyplot as plt

labels = ['sep', 'par', 'par_unseq']
lines_style = [':', '--', '-.']
data_files = []
data_np = []
linewidth = 1
markersize = 3

figure_name = sys.argv[-1]


# Extract data from txt files
data_np = np.loadtxt(sys.argv[1], dtype=np.float64, skiprows=0, delimiter=' ')

n = (data_np[:, 0]).astype(int)

# Efficiency calculation
Delta = np.absolute(data_np[:, -1])


# Plot

plt.ylabel(" $|\Delta \pi |  / \pi $ [%]")
plt.xlabel("N")
plt.title("$| \Delta \pi|  /  \pi $ [%]  with Monte Carlo estimation")

plt.xscale("log", base=10)
plt.yscale("log", base=10)
plt.plot(n, Delta, lines_style[1], linewidth=linewidth, marker='o', markersize=markersize)

plt.grid(linestyle='--', linewidth=0.3)
plt.savefig(figure_name, format="pdf", bbox_inches="tight")
# plt.show()
