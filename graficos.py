import numpy as np
import matplotlib.pyplot as plt

# Nome do arquivo com os dados
arquivo = "graficos.txt"

# Carregar os dados
dados = np.loadtxt(arquivo)

# Separando as colunas
xc = dados[:, 0]
yc = dados[:, 1]
xref = dados[:, 2]
yref = dados[:, 3]


# --- Gráfico 1: trajetória real (xc vs yc)
plt.figure()
plt.plot(xc, yc, label="Trajetória Real", linewidth=2)
plt.title("Trajetória Real do Robô")
plt.xlabel("Posição Xc")
plt.ylabel("Posição Yc")
plt.axis('equal')
plt.grid(True)
plt.legend()

# --- Gráfico 2: trajetória de referência (xref vs yref)
plt.figure()
plt.plot(xref, yref, label="Trajetória de Referência", linestyle='--', linewidth=2)
plt.title("Trajetória de Referência")
plt.xlabel("Posição Xref")
plt.ylabel("Posição Yref")
plt.axis('equal')
plt.grid(True)
plt.legend()


plt.show()