PARA EXECUTAR O PROGRAMA

SEM CARGA ----------------------

no terminal:

    make

    ./programa 

    (NO PROGRAMA)INFORME OS VALORES DE A1 E A2:
    3 3
    
    //AO INFORMAR OS VALORES, SERÃO CRIADOS VARIOS ARQUIVOS .TXT QUE SERAO UTILIZADOS PARA ANALISE DOS DADOS E SEUS GRAFICOS
        
        graficos.txt
        controle.txt
        linearizacao.txt
        modelref.txt
        startref.txt
        robo.txtpython
        interface.txt

    python3 analise.py //FAZ A ANALISE DOS DADOS DAS THREADS E SEUS JITTERS, IMPRIME OS RESULTADOS NO TERMINAL

    python3 graficos.py //GERA OS GRÁFICOS



COM CARGA -----------------------

Para simular carga no sistema:

    sudo apt update

    sudo apt install stress-ng 

    stress-ng --cpu 12 --io 2 --vm 1 --vm-bytes 99% --timeout 3m

no terminal:

    make

    ./program 

    (NO PROGRAMA)INFORME OS VALORES DE A1 E A2:
    3 3

    python3 analise.py

    python3 graficos.py


