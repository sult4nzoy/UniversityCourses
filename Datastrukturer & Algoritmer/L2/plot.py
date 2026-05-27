import matplotlib.pyplot as plotter

filer = [
    "insertion_sort.txt", 
    "selection_sort.txt", 
    "quick_sort_partition.txt", 
    "quick_sort_median.txt", 
    "std_sort.txt"
]

def plot_data(filnamn):
    all_data = {} 
    with open(filnamn, "r") as f:
        text = f.read()
    
    sektioner = text.split("-----------------------")
    for sektion in sektioner:
        if "Ordning:" in sektion:
            rader = sektion.strip().split("\n")
            vektor_typ = ""
            n_lista = []
            tid_lista = []

            for rad in rader:
                if "Ordning:" in rad:
                    vektor_typ = rad.split(":")[1].strip()
                elif "N:" in rad:
                    storlek = rad.split(":")[1].strip()
                    n_lista.append(int(storlek))
                elif "T[ms]:" in rad:
                    medel = rad.split(":")[1].strip()
                    tid_lista.append(float(medel))
            
            if vektor_typ and n_lista:
                all_data[vektor_typ] = (n_lista, tid_lista)
                   
    return all_data

for fil in filer:
    resultat = plot_data(fil)
    
    plotter.figure(figsize=(10, 6))
    
    for vektor_typ, (n, tid) in resultat.items():
        plotter.plot(n, tid, marker='o', label=vektor_typ)
   
    
    plotter.title(f"Algoritm: {fil}")
    plotter.xlabel("N")
    plotter.ylabel("T[ms]")
    plotter.grid(True)
    plotter.legend()

plotter.show()