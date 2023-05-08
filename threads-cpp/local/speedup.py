import sys
import numpy as np
import matplotlib.pyplot as plt

labels = ['sep', 'par', 'par_unseq']
data_files = []
data_np = []
linewidth = 1

for i in range(1, len(sys.argv), 1):
    data_files.append(i)

figure_name = sys.argv[-1]

# Extract data from txt files
# title = np.loadtxt(file_data_1, dtype='str', max_rows=1)

for i in data_files:
    data_np.append(np.loadtxt(i, dtype=np.float64, skiprows=0, delimiter=' '))


n = data_np[0][:, 0]

# Speedup calculation
for i in range(len(labels)):
    data_np[i][:, 1] = data_np[i][0, 0]/data_np[i][:, 1]

# Plot

plt.ylabel("Speedup $[s/s]$")
plt.xlabel("Thread")
plt.title("8 physical cores and 8 logics")

for i in range(len(labels)):
    plt.plot(n, data_np[i][:, 1], linewidth=linewidth, label=labels[i])

plt.plot(n, n, label="Theorical")
plt.legend()
plt.grid(linestyle='--', linewidth=0.3)
plt.savefig(figure_name, format="pdf", bbox_inches="tight")
# plt.show()
