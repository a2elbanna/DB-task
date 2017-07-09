/*******************/
/* D-äres Heapsort */
/*******************/

// Folgende Werte für D werden getestet:
const int D_MIN =  2;
const int D_MAX = 16;

/*
  Sei 'A[0..N-1]' die Arraydarstellung eines D-ären Heaps (linksvollständiger
  D-ärer Baum mit Min-Heapordnung, dessen Knoten in 'A' in Levelorder-Reihen-
  folge gespeichert sind) mit N Knoten und mit einer Fehlstelle am Knoten mit
  Index 'p'. (D.h., verringert man den Schlüssel von 'A[p]', wird 'A' zum Heap).
  Der Aufruf 'BubbleDown(A, N, p, D)' soll 'A' reparieren.

  Hinweis:
   1. Der Schlüssel des Elements 'A[i]' ist 'A[i].key()'.
  2a. Schlüssel haben den Typ 'T::KeyType',
  2b. Zwei Schlüssel 'k0' und 'k1' können mit den Operatoren
      'k0<k1', 'k0<=k1', 'k0>k1' und 'k0>=k1' verglichen werden.
   3. Arrayeinträge haben den Typ 'T'.

  Für eine effiziente Implementierung (kümmern Sie sich zunächst um Korrektheit!):
   4. Vermeiden Sie, den Schlüssel desselben Array-Elements mehrfach zu berechnen
      (speichern Sie den Schlüssel in einer lokalen Variable.)
   5. Vermeiden Sie, Einträge von Vater- und Kindknoten stets zu tauschen,
      benutzen Sie folgende Idee:
      Sei A[i0]=a0, A[i1]=a1, ..., A[iM]=aM eine Sequenz der von 'BubbleDown'
      bearbeiteten (d.h. getauschten) Knoten vor der Bearbeitung.
      Der Effekt von
         swap(A[i0], A[i1]); swap(A[i1], A[i2]); ... swap(A[i(M-1)], A[iM]);
      ist
         A[i0]=a1, A[i1]=a2, ..., A[i(M-1)]=aM, A[iM]=a0.
      Derselbe Effekt kann durch eine Sequenz von Zuweisungen erzeugt werden:
         T tmp=A[i0]; A[i0]=A[i1]; A[i2]=A[i3]; ... A[i(M-1)]=A[iM]; A[iM]=tmp;
      Statt drei Zuweisungen (swap) benötigt man nur eine Zuweisung pro Array-
      zelle zzgl. der Zuweisung von 'tmp'! */
template<typename T>
inline void BubbleDown( vector<T> &A, const int N, int p, const int D ) {
  typedef typename T::KeyType K;
  /// TODO Anfang
 // child array to store indexes of all
    // the children of given node
    int child[D+1];

    while (1)
    {
        // child[i]=-1 if the node is a leaf
        // children (no children)
        for (int i=1; i<=D; i++)
            child[i] = ((D*p + i) < N) ?
                    (D*p + i) : -1;

        // max_child stores the maximum child and
        // max_child_index holds its index
        int max_child = -1, max_child_index ;

        // loop to find the maximum of all
        // the children of a given node
        for (int i=1; i<=D; i++)
        {
            if (child[i] != -1 &&
                A[child[i]] > max_child)
            {
                max_child_index = child[i];
                max_child = A[child[i]];
            }
        }

        // leaf node
        if (max_child == -1)
            break;

        // swap only if the key of max_child_index
        // is greater than the key of node
        if (A[p] < A[max_child_index])
            swap(A[p], A[max_child_index]);

        p = max_child_index;
    }
  /// TODO Ende
}

/* Die Funktion 'MakeHeap(A, N, D)' arrangiert das Array 'A[0..N-1]' in einen
   D-ären Min-Heap um (Heapaufbauphase).

   Hinweis:
     1. In der Heapaufbauphase ist der erste Knoten, an dem etwas zu tun ist,
        der Vater vom Knoten mit Index N-1.
     2. Die Implementierung ist nur (etwa) zwei Zeilen! */
template<typename T>
void MakeHeap( vector<T> &A, const int N, const int D ) {
  /// TODO Anfang
   // Heapify all internal nodes starting from last
    // non-leaf node all the way upto the root node
    // and calling restore down on each
for (int i= (N-1)/D; i>=0; i--)
        BubbleDown(A, N, i, D);
  /// TODO Ende
}

/* Vorausgesetzt, das Array 'A[0..N-1]' ist ein D-ärer Min-Heap, sortiert die
   Funktion 'HeapSelect(A, N, D)' das Array 'A' absteigend.

   Hinweis:
     1. Die Funktion 'swap(A[i], A[j])' tauscht die Elemente 'A[i]' und 'A[j]'.
     2. Die Implementierung ist nur (etwa) drei Zeilen! */
template<typename T>
void HeapSelect( vector<T> &A, const int N, const int D ) {
  /// TODO Anfang

  /// TODO Ende
}

/* Die Funktion 'DAryHeapSort(A, N, D)' sortiert
   das Array 'A[0..N-1]' mit D-ärem Heapsort. */
template<typename T>
void DAryHeapSort( vector<T> &A, const int N, const int D ) {
    MakeHeap(A, N, D);
    HeapSelect(A, N, D);
}

/// TODO Anfang Exp4
const int BEST_D = 2; // hier in Experiment 1 ermittelten Wert für D eintragen
/// TODO Ende Exp4
