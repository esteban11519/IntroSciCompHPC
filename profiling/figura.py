import sys
import numpy as np
import matplotlib.pyplot as plt

# https://www.digitalocean.com/community/tutorials/python-command-line-arguments

results=sys.argv[1] # Archivo con resultados .txt (sys.argv[0] nombre del archivo al igual que c++)
figura_1=sys.argv[2] # Nombre archivo pdf para figura con barras de error
figura_2=sys.argv[3] # pdf para figura de la desvición estandar en función de nxm
figura_3=sys.argv[4] # pdf para figura de la media en función de nxm
n=int(sys.argv[5]) # Repeticiones de cada nxm

markersize=2
elinewidth=1

title=np.loadtxt(results,dtype='str',max_rows=1)
data=np.loadtxt(results,dtype=np.uint32,skiprows=1)

x=np.empty((int(data.shape[0]/n)),dtype=np.uint32)
y=np.empty((int(data.shape[0]/n),data.shape[1]-1),dtype=np.float64)
error=np.empty((int(data.shape[0]/n),data.shape[1]-1),dtype=np.float64)

contador=0
for i in range(0,data.shape[0],n):
    x[contador]=data[i,0]
    y[contador,:]=np.mean(data[i:i+n,1::],axis=0) 
    error[contador,:]=np.std(data[i:i+n,1::],axis=0)
    contador+=1


plt.ylabel("Time $[\mu s]$")
plt.xlabel(title[0])
plt.errorbar(x,y[:,0],yerr=error[:,0],fmt='o',markersize=markersize,elinewidth=elinewidth,label=title[1])
plt.errorbar(x,y[:,1],yerr=error[:,1],fmt='o',markersize=markersize,elinewidth=elinewidth,label=title[2])
plt.errorbar(x,y[:,2],yerr=error[:,2],fmt='o',markersize=markersize,elinewidth=elinewidth,label=title[3])
plt.errorbar(x,y[:,3],yerr=error[:,3],fmt='o',markersize=markersize,elinewidth=elinewidth,label=title[4])
plt.legend()
# plt.grid()
plt.savefig(figura_1, format="pdf", bbox_inches="tight")
# plt.show()

fig2 = plt.figure()

plt.ylabel("$\delta \; [\mu s]$")
plt.xlabel(title[0])
plt.plot(x,error[:,0],'o',markersize=markersize,label=title[1])
plt.plot(x,error[:,1],'o',markersize=markersize,label=title[2])
plt.plot(x,error[:,2],'o',markersize=markersize,label=title[3])
plt.plot(x,error[:,3],'o',markersize=markersize,label=title[4])
plt.legend()
plt.grid()
plt.savefig(figura_2, format="pdf", bbox_inches="tight")
# plt.show()

fig3 = plt.figure()

plt.ylabel("media $[\mu s]$")
plt.xlabel(title[0])
plt.plot(x,y[:,0],'o',markersize=markersize,label=title[1])
plt.plot(x,y[:,1],'o',markersize=markersize,label=title[2])
plt.plot(x,y[:,2],'o',markersize=markersize,label=title[3])
plt.plot(x,y[:,3],'o',markersize=markersize,label=title[4])
plt.legend()
plt.grid()
plt.savefig(figura_3, format="pdf", bbox_inches="tight")