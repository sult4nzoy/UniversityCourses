import matplotlib.pyplot as plotter
from matplotlib.ticker import ScalarFormatter

filer = [
    "linear_search.txt",
    "binary_search.txt",
    "bst_search.txt",
    "hash_search.txt"
]

def plot_data(filnamn):
    all_data = {} 
    try:
        with open(filnamn, "r") as f:
            rader = f.readlines()
    except FileNotFoundError:
        return all_data

    alg_typ = ""
    n_lista = []
    tid_lista = []

    for rad in rader:
        if "N:" in rad:
            n_lista.append(int(rad.split(":")[1].strip()))
        elif "Alg:" in rad:
            alg_typ = rad.split(":")[1].strip()
        elif "T[ns]:" in rad:
            tid_lista.append(float(rad.split(":")[1].strip()))

    if alg_typ and n_lista:
        all_data[alg_typ] = (n_lista, tid_lista)
            
    return all_data

for fil in filer:
    resultat = plot_data(fil)
    if not resultat:
        continue

    fig, ax = plotter.subplots(figsize=(12, 7))
    
    for alg_typ, (n, tid) in resultat.items():
        n_sorterad, tid_sorterad = zip(*sorted(zip(n, tid)))
        ax.plot(n_sorterad, tid_sorterad, marker='o', label=alg_typ)
    
    ax.xaxis.set_major_formatter(ScalarFormatter(useOffset=False))
    ax.ticklabel_format(style='plain', axis='x')
    ax.set_ylim(bottom=0)
    
    plotter.title(f"Algoritm: {fil}")
    plotter.xlabel("N")
    plotter.ylabel("T[ns]")
    plotter.grid(True)
    plotter.legend()

plotter.show()