from collections import deque

alpha = 0

class AhoCorasick:
    def __init__(self, patterns):
        global alpha
        self.alpha = alpha
        self.trie = [{}]  # Trie con el nodo raíz
        self.fail = [-1]  # Enlaces de retroceso
        self.output = [set()]  # Conjuntos de coincidencias de los patrones
        self.build_trie(patterns)
        self.build_failure()

    def build_trie(self, patterns):
        """ Construye el trie con los patrones dados. """
        for i, pattern in enumerate(patterns):
            node = 0  # Empezamos en la raíz
            for char in pattern:
                c = ord(char) - ord('a')  # Convertimos el carácter a su índice
                if c not in self.trie[node]:
                    self.trie[node][c] = len(self.trie)
                    self.trie.append({})
                    self.fail.append(-1)
                    self.output.append(set())
                node = self.trie[node][c]
            self.output[node].add(i)  # Al llegar a un nodo, agregamos el índice del patrón
    
    def build_failure(self):
        """ Construye los enlaces de retroceso usando BFS. """
        queue = deque()
        # Iniciamos los enlaces de retroceso de la raíz
        for c in range(self.alpha):
            if c in self.trie[0]:
                self.fail[self.trie[0][c]] = 0
                queue.append(self.trie[0][c])
            else:
                self.trie[0][c] = 0
        
        while queue:
            state = queue.popleft()
            for c, next_state in self.trie[state].items():
                # Establecemos el enlace de retroceso
                f = self.fail[state]
                while c not in self.trie[f]:
                    f = self.fail[f]
                self.fail[next_state] = self.trie[f][c]
                # Propagamos las coincidencias
                self.output[next_state].update(self.output[self.fail[next_state]])
                queue.append(next_state)

    def count_paths(self, m):
        """ Cuenta las rutas válidas de longitud m en el autómata. """
        # DP para contar las rutas, prev[x] representa el número de rutas que terminan en el nodo x
        prev = [0] * len(self.trie)
        prev[0] = 1  # Empezamos en el nodo raíz con 1 ruta válida
        
        for _ in range(m):
            current = [0] * len(self.trie)
            for state in range(len(self.trie)):
                # Si el nodo es final (tiene alguna coincidencia), no propagamos la ruta
                if len(self.output[state]) > 0:
                    continue  # No propagamos desde nodos finales
                for c in range(self.alpha):
                    next_state = self.trie[state].get(c, 0)
                    # Solo propagamos la ruta si el siguiente nodo no es final
                    if len(self.output[next_state]) == 0:
                        current[next_state] += prev[state]
            prev = current  # Actualizamos el dp con las nuevas rutas
        return sum(prev)

def main():
    global alpha

    # Leer los parámetros
    alpha, m, p = map(int, input().split())
    allowed = input().strip()
    
    # Mapeamos los caracteres del alfabeto
    mp = {allowed[i]: i for i in range(alpha)}
    
    # Leer los patrones y convertirlos a los índices correspondientes
    patterns = []
    for _ in range(p):
        pat = input().strip()
        transformed_pat = ''.join(chr(mp[c] + ord('a')) for c in pat)
        patterns.append(transformed_pat)
    
    # Crear el autómata de Aho-Corasick
    aho = AhoCorasick(patterns)
    
    # Contamos y mostramos el resultado
    print(aho.count_paths(m))

if __name__ == "__main__":
    main()
