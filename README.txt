PARA EXECUTAR O PROGRAMA

SEM CARGA ----------------------

no terminal:
    make

    ./program > output_sc.txt

    python3 analise.py

Arquivos criados:

    output_sc; grafico_2D; grafico_3D; periodos_jitters.txt; programa.exe





COM CARGA -----------------------

Para simular carga no sistema:

    sudo apt update

    sudo apt install stress-ng 

    stress-ng --cpu 12 --io 2 --vm 1 --vm-bytes 80% --timeout 3m

no terminal:

    make

    ./program > output_cc.txt

    python3 analise.py

Arquivos criados:

    output_cc; grafico_2D; grafico_3D; periodos_jitters.txt; programa.exe

NA PASTA SIMULAÇÔES ESTÂO O ARQUIVOS CRIADOS NAS DUAS SIMULAÇOES.

