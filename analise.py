import pandas as pd
import numpy as np

# Nome dos arquivos e identificação da thread
threads = {
    "startref": "startref.txt",
    "modelref": "modelref.txt",
    "linearizacao": "linearizacao.txt",
    "controle": "controle.txt",
    "interface": "interface.txt",
    "robo": "robo.txt"
}

resultados = []

for nome, arquivo in threads.items():
    # Carregar somente a primeira coluna (tempo)
    dados = np.loadtxt(arquivo, usecols=[0])

    # Calcular jitter (diferença absoluta entre tempos consecutivos)
    jitter = np.abs(np.diff(dados))

    # Calcular estatísticas
    resultados.append({
        "Thread": nome,
        "Media_Tempo": np.mean(dados),
        "Variancia_Tempo": np.var(dados),
        "Desvio_Tempo": np.std(dados),
        "Max_Tempo": np.max(dados),
        "Min_Tempo": np.min(dados),
        "Media_Jitter": np.mean(jitter),
        "Variancia_Jitter": np.var(jitter),
        "Desvio_Jitter": np.std(jitter),
        "Max_Jitter": np.max(jitter),
        "Min_Jitter": np.min(jitter)
    })

# Criar tabela
tabela = pd.DataFrame(resultados)

# Exibir tabela
print(tabela)


