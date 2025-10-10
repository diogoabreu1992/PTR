import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import os

arquivo = 'output.txt'

if not os.path.exists(arquivo):
    print(f"Erro: arquivo '{arquivo}' não encontrado.")
    exit(1)

# -----------------------
# Carregar dados
# -----------------------
dados = np.loadtxt(arquivo)

if dados.shape[1] < 6:
    print("Erro: o arquivo precisa ter pelo menos 6 colunas.")
    exit(1)

coluna1 = dados[:, 0]  # tempo
coluna4 = dados[:, 3]
coluna5 = dados[:, 4]
coluna6 = dados[:, 5]

# -----------------------
# Calcular períodos e jitter
# -----------------------
periodos = np.diff(coluna1)  # período entre execuções consecutivas
periodo_medio = np.mean(periodos)
periodo_variancia = np.var(periodos)
periodo_std = np.std(periodos)
periodo_max = np.max(periodos)
periodo_min = np.min(periodos)

jitter = periodos - 0.030
jitter_medio = np.mean(jitter)
jitter_variancia = np.var(jitter)
jitter_std = np.std(jitter)
jitter_max = np.max(jitter)
jitter_min = np.min(jitter)

# -----------------------
# Salvar períodos e estatísticas em arquivo
# -----------------------
saida = 'periodos_jitter.txt'
with open(saida, 'w') as f:
    f.write(f"{'Execução':>8} {'Período (ms)':>15} {'Jitter (ms)':>15}\n")
    for i, (p, j) in enumerate(zip(periodos, jitter), start=1):
        f.write(f"{i:>8} {p*1000:>15.3f} {j*1000:>15.3f}\n")

    f.write("\nEstatísticas dos Períodos:\n")
    f.write(f"Média: {periodo_medio*1000:.3f} ms\n")
    f.write(f"Variância: {periodo_variancia*1000:.6f} ms²\n")
    f.write(f"Desvio padrão: {periodo_std*1000:.3f} ms\n")
    f.write(f"Máximo: {periodo_max*1000:.3f} ms\n")
    f.write(f"Mínimo: {periodo_min*1000:.3f} ms\n")

    f.write("\nEstatísticas do Jitter:\n")
    f.write(f"Média: {jitter_medio*1000:.3f} ms\n")
    f.write(f"Variância: {jitter_variancia*1000:.6f} ms²\n")
    f.write(f"Desvio padrão: {jitter_std*1000:.3f} ms\n")
    f.write(f"Máximo: {jitter_max*1000:.3f} ms\n")
    f.write(f"Mínimo: {jitter_min*1000:.3f} ms\n")

print(f"Arquivo '{saida}' criado com períodos, jitters e estatísticas.")

# -----------------------
# Gráfico 2D: coluna 4 vs coluna 5
# -----------------------
fig2d = plt.figure(figsize=(8,5))
plt.plot(coluna4, coluna5, marker='.', linestyle='-', color='black', linewidth=0.8)
plt.xlabel('Xc (Coluna 4)')
plt.ylabel('Yc (Coluna 5)')
plt.title('Trajetória do Robô (2D)')
plt.grid(True)
plt.savefig('grafico_2D.png', dpi=300)

# -----------------------
# Gráfico 3D: coluna 4, 5 e 6
# -----------------------
fig3d = plt.figure(figsize=(8,6))
ax = fig3d.add_subplot(111, projection='3d')
ax.plot(coluna4, coluna5, coluna6, color='black', linewidth=0.8)
ax.set_xlabel('Xc (Coluna 4)')
ax.set_ylabel('Yc (Coluna 5)')
ax.set_zlabel('Theta (Coluna 6)')
ax.set_title('Trajetória do Robô (3D)')
plt.savefig('grafico_3D.png', dpi=300)

# -----------------------
# Exibir as duas figuras
# -----------------------
plt.show()
