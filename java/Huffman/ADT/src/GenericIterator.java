import java.util.Iterator;

public class GenericIterator<T extends Comparable<T>> implements Iterator<T> {
    private Node<T> initial;

    private Node<T> ref;

    public GenericIterator(Node<T> ref) {
        this.ref = ref;
        this.initial = ref;
    }

    @Override
    public boolean hasNext() {
        return this.ref != null;
    }

    @Override
    public T next() {
        Node<T> current = this.ref;
        this.ref = this.ref.getNext();
        return current.getT();
    }

    public void reset()
    {
        this.ref = this.initial;
    }
}
