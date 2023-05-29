import sys
import numpy as np
import matplotlib.pyplot as plt

# labels = ['sep', 'par', 'par_unseq']
lines_style = [':', '--', '-.']
data_files = []
data_np = []
linewidth = 1
markersize = 3

figure_name = sys.argv[-1]

# Extract data from txt files
# title = np.loadtxt(file_data_1, dtype='str', max_rows=1)

data_np = np.loadtxt(sys.argv[1], dtype=np.float64, skiprows=0, delimiter=' ')

# process
n = (data_np[:, 0]).astype(int)

# Speedup calculation
S = data_np[0, 1]/data_np[:, 1]

# Plot

plt.ylabel("Speedup $[s/s]$")
plt.xlabel("Process")
plt.title("Speedup with OpenMPI")
plt.plot(n, S, lines_style[1], linewidth=linewidth, marker='o', markersize=markersize, label="Experimental")
plt.plot(n, n, label="Theorical", linewidth=linewidth)
plt.legend()
plt.grid(linestyle='--', linewidth=0.3)
plt.savefig(figure_name, format="pdf", bbox_inches="tight")
# plt.show()
