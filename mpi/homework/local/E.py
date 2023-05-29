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
# title = np.loadtxt(file_data_1, dtype='str', max_rows=1)

data_np = np.loadtxt(sys.argv[1], dtype=np.float64, skiprows=0, delimiter=' ')

n = (data_np[:, 0]).astype(int)

# Efficiency calculation
E = data_np[0, 1]/(data_np[:, 1]*n)

# Plot

plt.ylabel("$\eta _p [s/s]$")
plt.xlabel("Process")
plt.title("Parallel Efficiency with OpenMPI")

plt.plot(n, E, lines_style[1], linewidth=linewidth, marker='o', markersize=markersize, label="Experimental")
plt.plot(n, np.ones(len(n)), linewidth=linewidth, label="Theorical")
plt.plot(n, 0.6*np.ones(len(n)), linewidth=linewidth, label="0.6")

# plt.legend(loc='upper right')
plt.legend()
plt.grid(linestyle='--', linewidth=0.3)
plt.savefig(figure_name, format="pdf", bbox_inches="tight")
# plt.show()
