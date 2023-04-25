import sys
import numpy as np
import matplotlib.pyplot as plt

# https://www.digitalocean.com/community/tutorials/python-command-line-arguments

file_data_1 = sys.argv[1]  # Archivo con resultados .txt (sys.argv[0] nombre del archivo al igual que c++)
file_data_2 = sys.argv[2]

markersize = 3
elinewidth = 1

# Extract data from txt files
title = np.loadtxt(file_data_1, dtype='str', max_rows=1)
data_1 = np.loadtxt(file_data_1, dtype=np.float64, skiprows=1)
data_2 = np.loadtxt(file_data_2, dtype=np.float64, skiprows=1)


plt.ylabel("Time $[\mu s]$")
plt.xlabel(title[0])
plt.errorbar(x,y[:,0],yerr=error[:,0],fmt='^',markersize=markersize,elinewidth=elinewidth,label=title[1])
plt.errorbar(x,y[:,1],yerr=error[:,1],fmt='s',markersize=markersize,elinewidth=elinewidth,label=title[2])
plt.errorbar(x,y[:,2],yerr=error[:,2],fmt='o',markersize=markersize,elinewidth=elinewidth,label=title[3])
plt.errorbar(x,y[:,3],yerr=error[:,3],fmt='x',markersize=markersize,elinewidth=elinewidth,label=title[4])
plt.legend()
plt.grid()
plt.savefig(figura_1, format="pdf", bbox_inches="tight")
# plt.show()

