
public class Main {
  public static void main(String[] args) {
    Arbol arbol = new Arbol();
  }
}

class Arbol {
  private Nodo raiz;

  public Arbol() {}

  public boolean agregarNodo(int valor) {
    if (raiz == null) {
      raiz = new Nodo(valor);
      return true;
    }
    return raiz.agregarNodo(valor);
  }
}

class Nodo {
  private Nodo izq, der;
  private int valor;

  public Nodo(int valor) {
    this.valor = valor;
  }

  public boolean agregarNodo(int valor) {
    if (valor < this.valor) {
      if (izq == null) {
        izq = new Nodo(valor);
        return true;
      }
      return izq.agregarNodo(valor);
    }
    if (valor > this.valor) {
      if (der == null) {
        der = new Nodo(valor);
        return true;
      }
      return der.agregarNodo(valor);
    }
    return false;
  }


}