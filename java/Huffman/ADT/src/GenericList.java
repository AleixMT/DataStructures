import java.util.Iterator;

public class GenericList<T extends Comparable<T>> implements Iterable<T> {

    private Node<T> first;

    public GenericList() {
        this.first = null;
    }

    public void add (T t) {
        if (this.first == null)
        {
            this.first = new Node<T>(t);
        }
        else
        {
            Node<T> aux = this.first;
            while (aux.getNext() != null)
            {
                aux = aux.getNext();
            }
            // aux is now the last element of the list
            aux.setNext(new Node<>(t));
        }
    }

    public int remove(T t) {
        int elements_removed = 0;
        if (this.first == null)
        {
            return 0;
        }
        else
        {
            Node<T> aux = this.first;
            while (aux.getT().compareTo(t) == 0)
            {
                elements_removed++;
                aux = aux.getNext();
                // Remove sequence of possible first elements matching
                this.first = aux;
            }
            // aux is the first element in the list and is not matching
            while (aux.getNext() != null)
            {
                // If the next is matching
                if (aux.getNext().getT().compareTo(t) == 0) {
                    elements_removed++;
                    // Delete it by skiping the node changing the pointer
                    aux.setNext(aux.getNext().getNext());
                    // To detect a null pointer if we are deleting the last element of the list
                    if (aux.getNext() == null) {
                        return elements_removed;
                    }
                }
                else
                {
                    aux = aux.getNext();
                }
            }
            return elements_removed;
        }
    }

    public T get(int position)
    {
        Node<T> aux = this.first;
        for (int i = 0; i < position; i++)
        {
            aux = aux.getNext();
            if (aux == null)
            {
                return null;
            }
        }
        return aux.getT();
    }

    public T search(T t)
    {
        Node<T> aux = this.first;
        while (aux != null)
        {
            if (aux.getT().compareTo(t) == 0)
            {
                return aux.getT();
            }
            aux = aux.getNext();
        }
        return null;
    }

    @Override
    public Iterator<T> iterator() {
        return new GenericIterator<>(this.first);
    }
}
